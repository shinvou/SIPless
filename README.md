# SIPless
## Change SIP configuration without recovery mode

### Intro
SIPless is a fast way to change your SIP settings. It's simple and does not feature any kind of status bar app cuz it's just a POC more or less.
SIP needs to be disabled, well at least the kext loading part, to get this to load. SIP exploits not included. ;P

### How do I SIPless?
You need to build and load the kext. Look at the source code, there's the line
```
set_csr(CSR_ALLOW_UNTRUSTED_KEXTS | CSR_ALLOW_UNRESTRICTED_NVRAM);
```
which changes your SIP configuration. Change the arguments to your preferred SIP configuration. All available arguments are in csr.h.

### How do I get?
You should know that.

### How do I compile?
You should know that, too. :P

### License?
Pretty much the BSD license, just don't repackage it and call it your own please!

Also if you do make some changes, feel free to make a pull request and help make things more awesome!

### Contact Info?
If you have any support requests please feel free to email me at shinvou[at]gmail[dot]com.

Otherwise, feel free to follow me on twitter: [@biscoditch](https:///www.twitter.com/biscoditch)!

### Special Thanks
- Apple for the xnu-4570.1.46 sources (kern_csr.c/csr.h)

- Siguza for [hsp4.kext](https://github.com/Siguza/hsp4) where I took his symbol solver from (sym.c/sym.h)
