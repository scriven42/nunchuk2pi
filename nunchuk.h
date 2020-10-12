/* by xerpi (c) 2013 */

#ifndef _NUNCHUK_H_
#define _NUNCHUK_H_

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <linux/uinput.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define NUNCHUK_ADDRESS      0x52
#define NUNCHUK_DATA_LENGTH  6
#define NUNCHUK_REQ_MIN_FREQ 1
#define NUNCHUK_REQ_MAX_FREQ 1000
#define NUNCHUK_THREAD_ARG   "Nunchuk thread"
#define NUNCHUK_REINIT_DELAY 500 * 1000

struct nunchuk {
	uint8_t X, Y, Z, C;
	uint16_t aX, aY, aZ;
};

typedef void (*nuncuk_read_callback)(int);


int nunchuk_init_nunchuk();
int nunchuk_init(struct nunchuk* n);
int nunchuk_read_data(struct nunchuk* n);
int nunchuk_exit();
inline int nunchuk_is_initiated();
void nunchuk_set_request_freq(int new_freq);
int nunchuk_get_request_freq();
void nunchuk_set_read_callback(nuncuk_read_callback func);

static inline __s32 i2c_smbus_access(int file, char read_write, __u8 command,
                                     int size, union i2c_smbus_data *data)
{
        struct i2c_smbus_ioctl_data args;

        args.read_write = read_write;
        args.command = command;
        args.size = size;
        args.data = data;
        return ioctl(file,I2C_SMBUS,&args);
}

static inline __s32 i2c_smbus_write_byte(int file, __u8 value)
{
        return i2c_smbus_access(file,I2C_SMBUS_WRITE,value,
                                I2C_SMBUS_BYTE,NULL);
}

static inline __s32 i2c_smbus_write_byte_data(int file, __u8 command,
                                              __u8 value)
{
        union i2c_smbus_data data;
        data.byte = value;
        return i2c_smbus_access(file,I2C_SMBUS_WRITE,command,
                                I2C_SMBUS_BYTE_DATA, &data);
}


#endif
