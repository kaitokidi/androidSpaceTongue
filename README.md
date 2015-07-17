AndroidGravity
==============

Android Version of Space Tongue

Programmed by Genís Bayona, Gonzalo Diez, Guillem Godoy, 
with graphics from Julieta Larrea,
with the help of Núria Margarit 

Ported to Android using the SFML android lib by Genís Bayona.

Touch the chamaleons to lick the spacial penguin and guide him to the big chamaleon.


To use it, you will need SFML libs, 
on Ubuntu 14 they are already included, in another Operating sistem, 
you will need to install them For Windows, in Visual studio (http://www.sfml-dev.org/tutorials/2.2/start-vc.php) 
for Linux users (http://www.sfml-dev.org/tutorials/2.2/start-linux.php), 
and for MAC OS (http://www.sfml-dev.org/tutorials/2.2/start-osx.php) .

Also it is compiled using the android NDK and the special Developement features of SFML for Android.


cd jni
ndk-build
cd ..
ant debug install
