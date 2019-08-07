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


#### build

The build system uses bazel. You can get it at https://github.com/bazelbuild/bazel/releases

Binaries are produced in the *bazel-bin* folder.

Build library and examples:

    bazel build :all

Build library and examples with debug symbols:

    bazel build -c dbg :all

Build only the library:

    bazel build :nascodec-cpp

Clean build directories:

    bazel clean

#### testing

In order to test library, we use example programs in the example *folder*.

Each program must return an error code if it fails.
Most of the time error handling do not be need to be coded because the library throws exception when an error occurs.

Note: These example sources are used as is in the documentation.

Launch integration tests:

    bazel test :all

#### build documentaion

libnascodec-cpp uses doxygen for documentation.
You can generate it with the following command:

    doxygen libnascodec-cpp.cfg

It produces the documentation in the following repositories:

- doc/html
- doc/latex

#### debugging

The library produces dumps of packet compatible with wireshark.

For example, if you execute the program *bazel-bin/_5GS_code_PDU_session_establishment_request*, it produces this output:

```
~ bazel-bin/_5GS_code_PDU_session_establishment_request
00000 2e 03 1f c1 00 ff 93    .......
size = 7 | size of buffer = 7
PDU_session_establishment_request(PDU session Identity=PDU session identity value 3, Procedure transaction identity=31, Message type=PDU_session_establishment_request, Integrity protection maximum data rate=uplink(64 kbps)&downlink(Full data rate), PDU session type=IPv4v6)
00000 00 00 00 00 00 00 00 00 ........
00008 00 00 00 00 08 00 45 02 ......E.
00010 00 43 00 01 40 00 40 84 .C..@.@.
00018 3c 25 7f 00 00 01 7f 00 <%......
00020 00 01 df b0 96 0c ea 4c .......L
00028 f5 4b 00 00 00 00 00 03 .K......
00030 00 23 20 bc ec 86 00 00 .#......
00038 00 00 00 00 00 00 00 0f ........
00040 40 0f 00 00 01 00 26 00 @.....&.
00048 08 07 2e 03 1f c1 00 ff ........
00050 93                      .
```

Copy this part in a file, for example *test.hex*:

```
00000 00 00 00 00 00 00 00 00 ........
00008 00 00 00 00 08 00 45 02 ......E.
00010 00 43 00 01 40 00 40 84 .C..@.@.
00018 3c 25 7f 00 00 01 7f 00 <%......
00020 00 01 df b0 96 0c ea 4c .......L
00028 f5 4b 00 00 00 00 00 03 .K......
00030 00 23 20 bc ec 86 00 00 .#......
00038 00 00 00 00 00 00 00 0f ........
00040 40 0f 00 00 01 00 26 00 @.....&.
00048 08 07 2e 03 1f c1 00 ff ........
00050 93                      .
```

Then you can import it in wireshark,
- open file menu
- select import from dump hex, a dialog opens
- fill file name in the dialog, don't touch to other options
- click on import

The *bazel-bin/_5GS_code_PDU_session_establishment_request* output anything to stderr, but the dump, so you can redirect its output:

```
~ bazel-bin/_5GS_code_PDU_session_establishment_request > test.hex
00000 2e 03 1f c1 00 ff 93    .......
size = 7 | size of buffer = 7
PDU_session_establishment_request(PDU session Identity=PDU session identity value 3, Procedure transaction identity=31, Message type=PDU_session_establishment_request, Integrity protection maximum data rate=uplink(64 kbps)&downlink(Full data rate), PDU session type=IPv4v6)
```

Note that to decode NAS messages they must be encapsulated into S1AP or NGAP messages.

In order to decode a 5GS nas packet, you need wireshark >= 3.1

