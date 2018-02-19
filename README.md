# manual-tux
send and receive arbitrary bytes to and from serial for ECE391 tux controller testing

valid formats are xnn for hex number, bnnnnnnnn for binary, separate with comma and no space.

Eg to set 7 segment to display "Good" send xc6,x0f,b01001111,b01001101,b01001101,b11100101

Binary download at https://github.com/dennis97519/manual-tux/releases

[![Build status](https://ci.appveyor.com/api/projects/status/jwoy6eu3oxk2gc3t?svg=true)](https://ci.appveyor.com/project/dennis97519/manual-tux)
