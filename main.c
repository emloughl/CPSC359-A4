#include <stdio.h>

int main()
{
	init();

	
	int powerSave;
	float x = 1;
	float y = 1;
	float z = 1;
	
	int counter = 0;
	
	
	powerSave = read_byte(0x53, 0x2D);
	//turn on powersave
	printf("Standby on: 0x%02x\n", powerSave);
	
	powerSave = powerSave + 8;
	
	write_byte(0x53, 0x2D, powerSave);
	powerSave = read_byte(0x53, 0x2D);	
	printf("Standby off: 0x%02x\n", powerSave);

	// Print out accelerometer data
	while(counter < 100)
	{
		x = read_byte(0x53, 0x32);
		y = read_byte(0x53, 0x34);		
		z = read_byte(0x53, 0x36);	
		printf("(x,y,z) = (%.2f, %.2f, %.2f)\n", x, y, z);
		
		usleep(25000);
		counter = counter + 1;
		
	}
	
	powerSave = 0;
	write_byte(0x53, 0x2D, powerSave);
	powerSave = read_byte(0x53, 0x2D);
	printf("Standby on: 0x%02x\n", powerSave);
	
	
	
	
	int devID;
	devID = read_byte(0x53, 0x00);
	printf("DevID = 0x%02x\n", devID); 
	uninit();
	

	return 0;	

}
