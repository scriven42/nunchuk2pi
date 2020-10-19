nunchuk2pi
==========

Connect Wii nunchuk to the Raspberry Pi (Linux)

I added a hard-coded proportional limit to how fast the mouse moves, which I found worked better, but there were no other functional changes from xerpi's original.

Getting started
===============

Make sure you have everything you need for I2C.

    sudo apt-get install i2c-tools libi2c-dev
    
Activate I2C in the Raspberry Pi config:

    sudo raspi-config
   
Go to interfacing options and I2C, choose to enable it.

To compile the nunchuk2pi code, go to the directory where you unpacked it and write:

    make

To run it:

    sudo ./n2pi
    
    
Credits
=======

Icon used for Tint2 Executor: https://www.flaticon.com/free-icon/wii-controller_668538
Icon made by https://www.flaticon.com/authors/smashicons/Smashicons from www.flaticon.com
And the no-nunchuck.png was created using https://www.online-image-editor.com/ by Adam Scriven 20201018
