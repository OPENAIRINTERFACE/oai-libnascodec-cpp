My Main Page                         {#mainpage}
============

Introduction
------------

libnascodec-cpp is a library for manipulating Network Access Stratum defined by 3gpp specification

It is intended to decode all NAS protocols, although the primary goal is on 5G system NAS messages.

@author Frederic Leroy <frederic.leroy@b-com.com>
@author Cyrille Benard <cyrille.benard@b-com.com>

### Features

#### 5G System NAS (TS 24.501)

PDU                               | IE support                             
--------------------------------- | --------------------------------------
for all PDUs                      | Extended protocol discriminator        
^                                 | PDU session identity                   
^                                 | Procedure transaction identity         
^                                 | Message type                           
PDU session establishment request | Integrity protection maximum data rate 
^                                 | PDU session type                       

#### debug


dump_wireshark

In order to decode a 5GS nas packet, you need wireshark >= 3.1



#### build

The build system uses bazel.

#### Unit testing