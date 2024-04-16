#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>

#include <goom/goom.h>

int canvasWidth = 800;
int canvasHeight = 800;
uint8_t canvasData[800*800*4] = {0};
PluginInfo* goom;
float floatVoice[2][512] = {{0}, {0}};
gint16 voice[2][512] = {{0}, {0}};
size_t voiceCount;

EM_JS(int, getRealWidth, (), { return Module.canvas.clientWidth; });

EM_JS(int, getRealHeight, (), { return Module.canvas.clientHeight; });

EM_JS(void, syncDataPointers, (int width, int height, uint8_t* imageData, float* leftVoice, float* rightVoice), {
	Module.imageData = new ImageData(new Uint8ClampedArray(Module.HEAPU8.buffer, imageData, width * height * 4), width, height);
	Module.leftVoice = new Float32Array(Module.HEAPF32.buffer, leftVoice, 512);
	Module.rightVoice = new Float32Array(Module.HEAPF32.buffer, rightVoice, 512);
});

EM_JS(void, drawToCanvas, (int width, int height), {
	Module.canvas.getContext("2d").putImageData(Module.imageData, width / 2 - 400, height / 2 - 400, 400 - width / 2, 400 - height / 2, width, height);
});

EM_JS(size_t, getVoiceData, (), {
	if(audioContext && audioContext.source) {
		audioContext.leftAnalyser.getFloatTimeDomainData(Module.leftVoice);
		if(audioContext.source.channelCount > 1) {
			audioContext.rightAnalyser.getFloatTimeDomainData(Module.rightVoice);
		}
		return audioContext.source.channelCount;
	}
	return 0;
});

void updateCanvasSize(void)
{
	canvasWidth = getRealWidth();
	canvasHeight = getRealHeight();
	
	if(canvasWidth >= canvasHeight)
	{
		canvasHeight = 800 * canvasHeight / canvasWidth;
		canvasWidth = 800;
		emscripten_set_canvas_element_size("#canvas", canvasWidth, canvasHeight);
	}
	else
	{
		canvasWidth = 800 * canvasWidth / canvasHeight;
		canvasHeight = 800;
		emscripten_set_canvas_element_size("#canvas", canvasWidth, canvasHeight);
	}
}

static EM_BOOL onWindowResize(int eventType, const EmscriptenUiEvent* event, void* userData)
{
	updateCanvasSize();
	return EM_TRUE;
}

static EM_BOOL onFrame(double time, void* userData)
{
	voiceCount = getVoiceData();
	
	for(size_t i = 0; i < 2; i++)
	{
		size_t j = i;
		if(i > voiceCount) j = voiceCount - 1;
		for(size_t k = 0; k < 512; k++)
		{
			if(floatVoice[j][k] >= 1.0f)
			{
				voice[i][k] = 32767;
			}
			else if(floatVoice[j][k] < -1.0f)
			{
				voice[i][k] = -32768;
			}
			else
			{
				voice[i][k] = (gint16) (floatVoice[j][k] * 32768.0f);
			}
		}
	}
	goom_update(goom, voice, 0, -1.0f, 0, 0);
	for(size_t i = 3; i < 800*800*4; i += 4)
	{
		canvasData[i] = 255;
	}
	drawToCanvas(canvasWidth, canvasHeight);
	return EM_TRUE;
}

int main(void)
{
	goom = goom_init((guint32) canvasWidth, (guint32) canvasHeight);
	if(!goom_set_screenbuffer(goom, (void*) canvasData)) return 1; //why does changing `return 1` to `printf("uh oh...\n")` change the generation?!
	
	syncDataPointers(canvasWidth, canvasHeight, canvasData, floatVoice[0], floatVoice[1]);
	emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 0, onWindowResize);
	updateCanvasSize();
	
	emscripten_request_animation_frame_loop(onFrame, NULL);
	
	//goom_close(goom); //why free memory even
	
	return 0;
}