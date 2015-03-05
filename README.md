# crc16
command line crc16 calculator

##using:
	crc16 <string> <string_length>

##samples:
	#!/bin/bash
	
	jsonFile='test/gsmcmd.json';
	mcPort='/dev/ttyUSB0';
	
	obj_dst=1;
	obj_src=3;
	message_type=2;
	
	jsonValue=$(<$jsonFile)
	len=${#jsonValue};
	
	crc=$(./crc16 "$jsonValue" $len);
	
	printf "===ssn1%04x%04x%02x%04x%s%04x\r" "$obj_dst" "$obj_src" "$message_type" "$len" "$jsonValue" "$crc" > $mcPort;
	
	echo File transferred

or

	#!/bin/bash
	
	jsonFile='test/loadprefs.json';
	mcPort='/dev/ttyUSB0';
	
	obj_dst=1;
	obj_src=3;
	message_type=2;
	
	jsonValue="{\"ssn\":{\"v\":1,\"obj\":1,\"cmd\":\"reboot\"}}";
	len=${#jsonValue};
	
	crc=$(./crc16 "$jsonValue" $len);
	
	printf "===ssn1%04x%04x%02x%04x%s%04x\r" "$obj_dst" "$obj_src" "$message_type" "$len" "$jsonValue" "$crc" > $mcPort;
	
	echo cmd reboot transferred

