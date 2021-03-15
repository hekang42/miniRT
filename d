Process:         miniRT [69481]
Path:            /Volumes/VOLUME/*/miniRT
Load Address:    0x10b06d000
Identifier:      miniRT
Version:         ???
Code Type:       X86-64
Parent Process:  zsh [49003]

Date/Time:       2021-03-15 11:39:16.356 +0900
Launch Time:     2021-03-15 11:39:12.442 +0900
OS Version:      Mac OS X 10.14.6 (18G8022)
Report Version:  7
Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
Analysis Tool Version:  Xcode 10.2.1 (10E1001)

Physical footprint:         36.6M
Physical footprint (peak):  36.6M
----

leaks Report Version: 4.0
Process 69481: 16390 nodes malloced for 9336 KB
Process 69481: 11 leaks for 336 total leaked bytes.

    11 (336 bytes) << TOTAL >>

      4 (128 bytes) ROOT LEAK: 0x7fd7fcf09e00 [32]
         3 (96 bytes) 0x7fd7fcf09da0 [32]
            1 (32 bytes) 0x7fd7fcf09dc0 [32]
            1 (32 bytes) 0x7fd7fcf09de0 [32]

      1 (48 bytes) ROOT LEAK: 0x7fd7fcf020a0 [48]

      2 (32 bytes) ROOT LEAK: 0x7fd7fcc0ee70 [16]
         1 (16 bytes) 0x7fd7fcf03f40 [16]

      1 (32 bytes) ROOT LEAK: 0x7fd7fcf01b90 [32]
      1 (32 bytes) ROOT LEAK: 0x7fd7fcf03c10 [32]
      1 (32 bytes) ROOT LEAK: 0x7fd7fcf03d50 [32]
      1 (32 bytes) ROOT LEAK: 0x7fd7fcf04670 [32]

