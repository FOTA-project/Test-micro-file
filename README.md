# Test-micro-file
A test file/project for the bootloader to test its functionality

## How to configure
1. Add the linker argument `-Xlinker --nmagic` to disable section allignment in the linker. \
   This allows addresses less than the default allignment `0x10000` to be used, \
   otherwise any address offset within the range [0x00000 - 0x0FFFF] will be floor()-ed down to 0x00000.
   
   ![project-settings](https://user-images.githubusercontent.com/59609326/83586783-a6ef8000-a54d-11ea-9a64-51af6acbf47b.png)
   
   ### References
   1. https://www.openstm32.org/forumthread5007
   2. https://stackoverflow.com/questions/15400910/ld-linker-script-producing-huge-binary
   3. https://linux.die.net/man/1/ld

2. In the linker script [mem.ld](bootloader-dummy-app/ldscripts/mem.ld) set the desired `ORIGIN` of the `FLASH`, it's set to `0x08002000` in this application.
