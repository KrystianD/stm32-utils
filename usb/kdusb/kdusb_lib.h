#ifndef __KDUSB_H__
#define __KDUSB_H__

#include "kdusb.h"
#include "usb_defs.h"

#include <stdint.h>

#define USB_REQTYPE_GETDIR(x) ((x) & 0x80)
#define USB_REQTYPE_GETTYPE(x) ((x) & 0x60)
#define USB_REQTYPE_GETRECIPIENT(x) ((x) & 0x1f)

#define USB_DIR_HOST_TO_DEVICE (0 << 7)
#define USB_DIR_DEVICE_TO_HOST (1 << 7)

#define USB_TYPE_STANDARD (0 << 5)
#define USB_TYPE_CLASS    (1 << 5)
#define USB_TYPE_VENDOR   (2 << 5)

#define USB_RECIPIENT_DEVICE    0
#define USB_RECIPIENT_INTERFACE 1
#define USB_RECIPIENT_ENDPOINT  2
#define USB_RECIPIENT_OTHER     3

#define USB_DIR_IS_DEVICE_TO_HOST(x) (USB_REQTYPE_GETDIR(x) == USB_DIR_DEVICE_TO_HOST)
#define USB_DIR_IS_HOST_TO_DEVICE(x) (USB_REQTYPE_GETDIR(x) == USB_DIR_HOST_TO_DEVICE)

#define USB_TYPE_IS_STANDARD(x) (USB_REQTYPE_GETTYPE(x) == USB_TYPE_STANDARD)
#define USB_TYPE_IS_CLASS(x) (USB_REQTYPE_GETTYPE(x) == USB_TYPE_CLASS)
#define USB_TYPE_IS_VENDOR(x) (USB_REQTYPE_GETTYPE(x) == USB_TYPE_VENDOR)

#define USB_RECP_IS_DEVICE(x) (USB_REQTYPE_GETRECIPIENT(x) == USB_RECIPIENT_DEVICE)
#define USB_RECP_IS_INTERFACE(x) (USB_REQTYPE_GETRECIPIENT(x) == USB_RECIPIENT_INTERFACE)
#define USB_RECP_IS_ENDPOINT(x) (USB_REQTYPE_GETRECIPIENT(x) == USB_RECIPIENT_ENDPOINT)

typedef enum USB_STANDARD_REQUESTS
{
  GET_STATUS = 0,
  CLEAR_FEATURE,
  RESERVED1,
  SET_FEATURE,
  RESERVED2,
  SET_ADDRESS,
  GET_DESCRIPTOR,
  SET_DESCRIPTOR,
  GET_CONFIGURATION,
  SET_CONFIGURATION,
  GET_INTERFACE,
  SET_INTERFACE,
  TOTAL_sREQUEST,  /* Total number of Standard request */
  SYNCH_FRAME = 12
} STANDARD_REQUESTS;

typedef enum USB_DESCRIPTOR_TYPE
{
  DEVICE_DESCRIPTOR = 1,
  CONFIG_DESCRIPTOR,
  STRING_DESCRIPTOR,
  INTERFACE_DESCRIPTOR,
  ENDPOINT_DESCRIPTOR,
	QUALIFIER_DESCRIPTOR,
} DESCRIPTOR_TYPE;

enum USBStates {
	NONE = 0,
	WAIT_STATUS_IN,
	WAIT_STATUS_OUT,
	IN_DATA,
	LAST_IN_DATA,
	OUT_DATA,
};

typedef struct
{
	uint8_t* descr;
	uint8_t len;
} USB_descriptorInfo;

#endif