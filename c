Process:         miniRT [69345]
Path:            /Volumes/VOLUME/*/miniRT
Load Address:    0x1097f7000
Identifier:      miniRT
Version:         ???
Code Type:       X86-64
Parent Process:  zsh [49003]

Date/Time:       2021-03-15 11:38:42.529 +0900
Launch Time:     2021-03-15 11:38:37.421 +0900
OS Version:      Mac OS X 10.14.6 (18G8022)
Report Version:  7
Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
Analysis Tool Version:  Xcode 10.2.1 (10E1001)

Physical footprint:         36.8M
Physical footprint (peak):  36.8M
----

leaks Report Version: 4.0
Process 69345: 16390 nodes malloced for 9338 KB
Process 69345: 5 leaks for 176 total leaked bytes.

    5 (176 bytes) << TOTAL >>
      1 (48 bytes) ROOT LEAK: 0x7fb038c0b850 [48]
      1 (32 bytes) ROOT LEAK: 0x7fb038c099a0 [32]
      1 (32 bytes) ROOT LEAK: 0x7fb038c0a890 [32]
      1 (32 bytes) ROOT LEAK: 0x7fb038c0ae10 [32]
      1 (32 bytes) ROOT LEAK: 0x7fb038c0c410 [32]

