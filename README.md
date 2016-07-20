# SodaLib

*Sonificating Data Library*, an open source multipurpose sonification tool for designers, programmers and creative practicioners. SodaLib’s core functions are written in [libPd](http://www.libpd.cc). That means, it is easily embeddable into many creative coding environments, including c++, java, python, etc. It also means, it is cross platform (has been tested on OSX, iOS, Raspberry Pi).

## Dependencies

[LibPd] (http://www.libpd.cc) can be added to your project using different methods, depending on your selection of language. For OpenFrameworks, use [ofxPd] (https://github.com/danomatika/ofxPd), read its install instructions carefully. 

## Folder Structure

The *lib* folder has everything that is related to the audio engine, it is a collection of [Pure Data](https://puredata.info/) patches. *main.pd* is called & opened upon every initialization. This patch handles the messages and synthesis parameters of the process. There are a few basic blocks that are generating sounds based on the messages sent to them. The *lib* folder must be placed into your project's data folder.

## Functions

SodaLib is communicating with libPd itself via some simple utility functions. When the program is started, it is generating the needed patches (sound generators) dynamically. When the program runs, it communicates with these generators with simple messages. Soda objects have a "set" function, individual generators can be addressed by calling this function with the generator's name as its argument. Pitch (shift), volume and pan can be modified at the moment. See the "Example" project for more details on how to initiate & address Soda objects. Use OpenFramework's project generator tool to create a project. Don't forget to add the [ofxPd](https://github.com/danomatika/ofxPd) addon to your project and set up the C flags as indicated. 

## Purpose

A polyphonic sampling engine (based on [polySample](https://github.com/stc/polySample) ) is made for sonifying discrete data structures, while a simple synth and filtered noise can be used to sonify continuous data streams from low dimensional to multidimensional data sources. Each of these requires no musical knowledge. More, specific examples coming soon. The following projects are made with SodaLib, so far: [SoundBow](http://www.binaura.net/apps/soundbow/), [SphereTones] (http://www.binaura.net/spheretones), [Echo](https://github.com/stc/echo) ~~ more on this soon

## Todo

Sonification examples. Chainable syntax. Migrate to Pd's clone object to generate & address patches dynamically instead of the current method.

-

All code is under GPLv3 Licensed unless otherwise stated. (c) Agoston Nagy / 2016
