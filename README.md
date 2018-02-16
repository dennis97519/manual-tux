# manual-tux
send and receive arbitrary bytes to and from serial for ECE391 tux controller testing

valid formats are xnn for hex number, bnnnnnnnn for binary, separate with comma and no space.

Eg to set 7 segment to display "Good" send xc6,x0f,b11100101,b01001101,b01001101,b01001111
