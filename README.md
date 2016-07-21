# SodaLib

*Sonificating Data Library*, an open source multipurpose sonification tool for designers, programmers and creative practicioners. SodaLib’s core functions are written in [libPd](http://www.libpd.cc). That means, it is easily embeddable into many creative coding environments, including c++, java, python, etc. It also means, it is cross platform (has been tested on OSX, iOS, Raspberry Pi).

## Dependencies

[LibPd] (http://www.libpd.cc) can be added to your project using different methods, depending on your selection of language. For OpenFrameworks, use [ofxPd] (https://github.com/danomatika/ofxPd), read its install instructions carefully. 

## Folder Structure

The *lib* folder has everything that is related to the audio engine, it is a collection of [Pure Data](https://puredata.info/) patches. *main.pd* is called & opened upon every initialization. This patch handles the messages and synthesis parameters of the process. There are a few basic blocks that are generating sounds based on the messages sent to them. The *lib* folder must be placed into your project's data folder.

## Functions

SodaLib is communicating with libPd itself via some simple utility functions. When the program is started, it is generating the needed patches (sound generators) dynamically. When the program runs, it communicates with these generators with simple messages. Soda objects have a "set" function, individual generators can be addressed by calling this function with the generator's name as its argument. Pitch (shift), volume and pan can be modified at the moment. See the "Example" project for more details on how to initiate & address Soda objects. Use OpenFramework's project generator tool to create a project. Don't forget to add the [ofxPd](https://github.com/danomatika/ofxPd) addon to your project and set up the C flags as indicated. 

## Purpose

SodaLib's purpose is to create a high level set of sonic tools that is focusing on representing data instead of musical concepts. Thus, you won't see traditional dsp building blocks like filters, effects etc here. While visualisation has really advanced concepts for interpreting highly complex multidimensional data, sonification lacks most of these, and what's out there are mainly accessible to creators with high-level musical (or dsp related) knowledge and experience. At the moment, SodaLib targets two key concepts of Sonification thus trying to make it available for a wider field of practitioners:
    
* Event based sonification (earcons, auditory icons, etc) >> the *sampling* block comes handy when dealing with this concept, see *discrete-data-example*
* Parameter mapping (multidimensional, realtime sensory data, etc) >> the *synthesis* block comes handy when dealing with this concept, see *continuous-datastream-example*

*auditory-display-example* shows how to create and access several hundreds of soda objects with just a few lines of code and use them for special sonification purposes, in this case, audio-cells of an (auditory) display with custom resolution: the volume of each cell is mapped to the cell's brightness value

A polyphonic sampling engine (based on [polySample](https://github.com/stc/polySample) ) is made for the sampling block, while a simple, yet easily extendable synth and a filtered noise block can be used to sonify continuous data streams from low dimensional to multidimensional data sources. Each of these requires no or minimal musical knowledge. 

The following projects are made with SodaLib so far: [SoundBow](http://www.binaura.net/apps/soundbow/), [SphereTones] (http://www.binaura.net/spheretones), [Echo](https://github.com/stc/echo) ~~ more on this soon

## Todo

More, specific sonification examples. Chainable syntax. Binaural sound positioning (useful for gaming & VR). Migrate to Pd's clone object to generate & address patches dynamically instead of the current method.

-

All code is under GPLv3 Licensed unless otherwise stated. (c) Agoston Nagy / 2016
