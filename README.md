# Goom On-Line

<a href="https://goom-online.github.io/"><img src="https://github.com/goom-online/goom-online.github.io/assets/1766353/98371331-da58-4adf-820a-0b61270a6cdb" alt="Logo"></a>

**Goom On-Line** is the Goom music visualizer ([SourceForge](https://sourceforge.net/projects/goom/)), created between 2001 and 2005 by Jean-Christophe Hoelt, now forked to turn it into a comfy web music player. And... it's right there, online. Just click the portal above!

# Usage 

0. **Make sure you don't suffer from photosensitive epilepsy. If you ever find that you're feeling worse after interacting with the following website, close it immediately and seek help.**
1. [Open the website](https://goom-online.github.io/).
2. Click somewhere on the website, outside of the logo, to open up a file chooser and choose a music piece, or...
3. ...drag and drop the music piece onto the website.
4. Double click somewhere on the website, outside of the logo, to toggle fullscreen.
5. While the music is being played, click anywhere on the website to stop it.
6. Return here, for example by clicking the logo... or "Learn ⋆ more ⋆ on ⋆ GitHub!", really a part of it.
7. <a href="#"><img height="24em" src="https://github.com/goom-online/goom-online.github.io/assets/1766353/b60161d0-0dd2-4136-84bf-4f12a3bba2cd" alt="Star me!"></a> Press this button.
8. Nooo, not here! Press it up above! Not this above!
9. Only ever repeat the steps 0-6, of which 2-6 in whatever order you find convenient.

:^)

# But where do I get _music files_ today??

This is probably how music visualizers lost their momentum in the first place... But: many places, still! Bandcamp, JunoDownload, Amazon (no affiliation implied)... Some keywords to look for, to find the best quality: **DRM-free, lossless, FLAC, WAV**.

For something slightly different but more specific, I am somewhat fond of pairing the visualizer with procedurally-generated ambient music, they fit well together; an artist by the name of Alex Bainter has created [a library of such music pieces that you may make recordings of, for free - and there are also pre-recorded excerpts!](https://play.generative.fm/browse)

# Building

You need a working Emscripten toolchain, CMake and the Ninja build tool in your PATH. Then just execute:

```sh
git clone https://github.com/goom-online/goom-online.github.io.git
cd goom-online.github.io
mkdir build
cd build
emcmake cmake -G Ninja ..
emmake ninja
```

With some luck, congratulations! It is built!

# License

LGPL. Like the original - see [ext/goom2k4-0-nologo/COPYING](https://github.com/goom-online/goom-online.github.io/blob/main/ext/goom2k4-0-nologo/COPYING).

# Donations

Ok, look, I didn't create Goom. Most of this is not mine. The author of Goom is Jean-Christophe Hoelt, and as there hasn't been much news for years, [I have no idea if he's actively taking the donations for which there is a seemingly-working button on this page](https://sourceforge.net/projects/goom/), but I am sure that he deserves them for Goom.

What I did was mostly just to bring up this interface that lets you use Goom on the web. Kind of like an attempt to make this piece of art known again. But sure enough, me also likes $. So if you were to insist on giving [me of all people](https://github.com/newbthenewbd) something:

[![Donate with PayPal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=sendmoney%40go2%2epl&lc=US&item_name=Donate%20to%20the%20GitHub%20user%20newbthenewbd&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHosted)

Thank you so much!
