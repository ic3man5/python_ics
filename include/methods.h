#ifndef _METHODS_H_
#define _METHODS_H_
#include <Python.h>
#include "object_vcan3_settings.h"
#include "object_fire_settings.h"
#include "object_neo_device.h"
#include "object_api_firmware_info.h"
#include "setup_module_auto_defines.h"

#ifdef _cplusplus
extern "C" {
#endif

PyObject* meth_find_devices(PyObject* self, PyObject* args, PyObject* keywords);
PyObject* meth_open_device(PyObject* self, PyObject* args, PyObject* keywords);
PyObject* meth_close_device(PyObject* self, PyObject* args);
PyObject* meth_get_rtc(PyObject* self, PyObject* args);
PyObject* meth_set_rtc(PyObject* self, PyObject* args);
PyObject* meth_coremini_load(PyObject* self, PyObject* args);
PyObject* meth_coremini_start(PyObject* self, PyObject* args);
PyObject* meth_coremini_stop(PyObject* self, PyObject* args);
PyObject* meth_coremini_clear(PyObject* self, PyObject* args);
PyObject* meth_coremini_get_status(PyObject* self, PyObject* args);
PyObject* meth_transmit_messages(PyObject* self, PyObject* args);
PyObject* meth_get_messages(PyObject* self, PyObject* args);
PyObject* meth_get_script_status(PyObject* self, PyObject* args);
PyObject* meth_get_error_messages(PyObject* self, PyObject* args);
#ifdef _USE_INTERNAL_HEADER_
PyObject* meth_flash_devices(PyObject* self, PyObject* args);
#endif // _USE_INTERNAL_HEADER_
PyObject* meth_set_reflash_callback(PyObject* self, PyObject* args);
PyObject* meth_get_device_settings(PyObject* self, PyObject* args);
PyObject* meth_set_device_settings(PyObject* self, PyObject* args);
PyObject* meth_load_default_settings(PyObject* self, PyObject* args); // icsneoLoadDefaultSettings
//PyObject* meth_spy_message_to_j1850(PyObject* self, PyObject* args);
PyObject* meth_read_sdcard(PyObject* self, PyObject* args);
PyObject* meth_write_sdcard(PyObject* self, PyObject* args);
PyObject* meth_create_neovi_radio_message(PyObject* self, PyObject* args, PyObject* keywords);
PyObject* meth_coremini_start_fblock(PyObject* self, PyObject* args); //ScriptStartFBlock
PyObject* meth_coremini_stop_fblock(PyObject* self, PyObject* args); //ScriptStopFBlock
PyObject* meth_coremini_get_fblock_status(PyObject* self, PyObject* args); //ScriptGetFBlockStatus
PyObject* meth_coremini_read_app_signal(PyObject* self, PyObject* args); //ScriptReadAppSignal
PyObject* meth_coremini_write_app_signal(PyObject* self, PyObject* args); //ScriptWriteAppSignal
PyObject* meth_coremini_read_tx_message(PyObject* self, PyObject* args); //ScriptReadTxMessage
PyObject* meth_coremini_read_rx_message(PyObject* self, PyObject* args); //ScriptReadRxMessage
PyObject* meth_coremini_write_tx_message(PyObject* self, PyObject* args); //ScriptWriteTxMessage
PyObject* meth_coremini_write_rx_message(PyObject* self, PyObject* args); //ScriptWriteRxMessage
PyObject* meth_get_performance_parameters(PyObject* self, PyObject* args);
PyObject* meth_validate_hobject(PyObject* self, PyObject* args);
PyObject* meth_get_last_api_error(PyObject* self, PyObject* args);
PyObject* meth_get_dll_version(PyObject* self, PyObject* args);
PyObject* meth_get_hw_firmware_info(PyObject* self, PyObject* args);
PyObject* meth_base36enc(PyObject* self, PyObject* args);
PyObject* meth_get_serial_number(PyObject* self, PyObject* args);
PyObject* meth_request_enter_sleep_mode(PyObject* self, PyObject* args);
PyObject* meth_set_context(PyObject* self, PyObject* args);
PyObject* meth_force_firmware_update(PyObject* self, PyObject* args);
PyObject* meth_firmware_update_required(PyObject* self, PyObject* args);
PyObject* meth_get_dll_firmware_info(PyObject* self, PyObject* args);






#ifdef _cplusplus
}
#endif

#define _EZ_ICS_STRUCT_METHOD(name, icsname, meth, flags, doc) \
    {name, (PyCFunction)meth, flags, doc}, \
    {icsname, (PyCFunction)meth, flags, "\n.. note::\n\tIdentical to PEP8 compliant :func:`" MODULE_NAME "." name "` method.\n\n"}

#define _EZ_ICS_STRUCT_METHOD_MULTIPLE(name, icsname, meth, flags, doc) \
    {icsname, (PyCFunction)meth, flags, "\n.. note::\n\tIdentical to PEP8 compliant :func:`" MODULE_NAME "." name "` method.\n\n"}

#define _DOC_FIND_DEVICES \
    MODULE_NAME".find_devices(device_type="MODULE_NAME".NEODEVICE_ALL)\n" \
    "\n" \
    "Args:\n" \
    "\tdevice_type (int): Accepts "MODULE_NAME".NEODEVICE_* Macros\n\n" \
    "\tstOptionsOpenNeoEx (int): Usually ics.NETID_CAN, if needed\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tTuple of :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` for use in :func:`"MODULE_NAME".open_device`\n" \
    "\n" \
    "\t>>> for device in ics.find_devices():\n" \
    "\t...     print(device.Name, device.SerialNumber)\n" \
    "\t...\n" \
    "\tneoVI FIRE 59886\n"


#define _DOC_OPEN_DEVICES \
    MODULE_NAME".open_device(device)\n" \
    "\n" \
    "Opens the device. `device` can be omitted to return a :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` of the\n" \
    "first free availible device, a :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`, or a serial number of the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tdevice (int): Serial Number of the device\n\n" \
    "\tbNetworkIDs (int): Network Enables\n\n" \
    "\tbConfigRead (int): Config Read\n\n" \
    "\tiOptions (int): DEVICE_OPTION_* defines\n\n" \
    "\tstOptionsOpenNeoEx (int): Usually ics.NETID_CAN, if needed\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tIf :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` is passed as a parameter, None. \n" \
    "\tIf serial number is passed as a parameter, a :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` will be returned. \n" \
    "\tIf `device` parameter is omitted, a :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` will be returned with the first availible free device. \n" \
    "\n" \
    "\t>>> for device in ics.find_devices():\n" \
    "\t...     ics.open_device(device)\n" \
    "\t...\n" \
    "\n" \
    ".. note::\n\t:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` will automatically close the device when it goes out of scope.\n\n"

#define _DOC_CLOSE_DEVICES \
    MODULE_NAME".close_device(device)\n" \
    "\n" \
    "Closes the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tError Count (int)\n" \
    "\n" \
    "\t>>> for device in ics.find_devices():\n" \
    "\t...     ics.open_device(device)\n" \
    "\t...     # Do something with the device...\n" \
    "\t...     ics.close_device(device)\n" \
    "\t...\n" \
    "\n" \
    ".. note::\n\t:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"` will automatically close the device when it goes out of scope.\n\n" \

#define _DOC_GET_RTC \
    MODULE_NAME".get_rtc(device)\n" \
    "\n" \
    "Gets the Real-Time Clock of the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tTuple: (datetime.datetime object, offset in seconds)\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.get_rtc(device)\n" \
    "\t(datetime.datetime(2014, 9, 10, 17, 45, 45), 3)\n"

#define _DOC_SET_RTC \
    MODULE_NAME".set_rtc(device[, time])\n" \
    "\n" \
    "Sets the Real-Time Clock of the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\time (:class:`datetime.datetime`): Optional. Sets to current time, if omitted.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.set_rtc(device)\n"

#define _DOC_COREMINI_LOAD \
    MODULE_NAME".coremini_load(device, coremini, location)\n" \
    "\n" \
    "Loads the CoreMini into the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tcoremini (str/tuple): Use string to load from file, Use Tuple if file data.\n\n" \
    "\tlocation (int): Accepts :class:`"MODULE_NAME".SCRIPT_LOCATION_FLASH_MEM`, :class:`"MODULE_NAME".SCRIPT_LOCATION_SDCARD`, or :class:`"MODULE_NAME".SCRIPT_LOCATION_VCAN3_MEM`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_load(device, 'cmvspy.vs3cmb', ics.SCRIPT_LOCATION_SDCARD)\n"

#define _DOC_COREMINI_START \
    MODULE_NAME".coremini_start(device, location)\n" \
    "\n" \
    "Starts the CoreMini into the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tlocation (int): Accepts :class:`"MODULE_NAME".SCRIPT_LOCATION_FLASH_MEM`, :class:`"MODULE_NAME".SCRIPT_LOCATION_SDCARD`, or :class:`"MODULE_NAME".SCRIPT_LOCATION_VCAN3_MEM`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_start(device, ics.SCRIPT_LOCATION_SDCARD)\n"

#define _DOC_COREMINI_STOP \
    MODULE_NAME".coremini_stop(device)\n" \
    "\n" \
    "Stops the CoreMini into the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_stop(device)\n"

#define _DOC_COREMINI_CLEAR \
    MODULE_NAME".coremini_clear(device, location)\n" \
    "\n" \
    "Clears the CoreMini into the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tlocation (int): Accepts :class:`"MODULE_NAME".SCRIPT_LOCATION_FLASH_MEM`, :class:`"MODULE_NAME".SCRIPT_LOCATION_SDCARD`, or :class:`"MODULE_NAME".SCRIPT_LOCATION_VCAN3_MEM`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_clear(device, ics.SCRIPT_LOCATION_SDCARD)\n"

#define _DOC_COREMINI_GET_STATUS \
    MODULE_NAME".coremini_get_status(device)\n" \
    "\n" \
    "Gets the status of the CoreMini in the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tTrue if running, otherwise False.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_get_status(device)\n" \
    "\t>>>\n"

#define _DOC_TRANSMIT_MESSAGES \
    MODULE_NAME".transmit_messages(device, messages)\n" \
    "\n" \
    "Transmits message(s) on the device. `messages` can be a tuple of :class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"`\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tmessages (:class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"`): :class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> msg = ics.SpyMessage()\n" \
    "\t>>> msg.ArbIDOrHeader = 0xFF\n" \
    "\t>>> msg.NetworkID = ics.NETID_HSCAN\n" \
    "\t>>> msg.Data = (0,1,2,3,4,5,6,7)\n" \
    "\t>>> ics.transmit_messages(device, msg)\n" \
    "\t>>>\n"

#define _DOC_GET_MESSAGES \
    MODULE_NAME".get_messages(device[, j1850, timeout])\n" \
    "\n" \
    "Gets the message(s) on the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tj1850 (:class:`bool`): Return :class:`"MODULE_NAME"."SPY_MESSAGE_J1850_OBJECT_NAME"` instead.\n\n" \
    "\timeout (:class:`float`): Optional timeout to wait for messages in seconds (0.1 = 100ms).\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t:class:`tuple` of two items. First item is a :class:`tuple` of :class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"` and second is the error count.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> messages, errors = ics.get_messages(device)\n" \
    "\t>>> len(messages)\n" \
    "\t14\n" \
    "\t>>> hex(messages[0].ArbIDOrHeader)\n" \
    "\t'0x160'\n" \
    "\t>>> messages[0].Data\n" \
    "\t(36, 11, 11, 177, 37, 3, 11, 199)\n" \
    "\t>>> errors\n" \
    "\t0\n"

//"Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME ", exception on error. Returns a list of (error #, string)"
#define _DOC_GET_ERROR_MESSAGES \
    MODULE_NAME".get_error_messages(device[, j1850, timeout])\n" \
    "\n" \
    "Gets the error message(s) on the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t:class:`list` of :class:`tuple`s. :class:`tuple` contents: (error_number, description_short, description_long, severity, restart_needed)\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> errors = ics.get_error_messages(device)\n"


//_DOC_SET_REFLASH_DISPLAY_CALLBACKS), "icsneoSetReflashCallback(), pass a python function func(msg, progress)"
#define _DOC_SET_REFLASH_CALLBACK \
    MODULE_NAME".set_reflash_callback(callback)\n" \
    "\n" \
    "Sets the reflash display callback.\n" \
    "\n" \
    "Args:\n" \
    "\tcallback (:class:`function`): Must be a callable Python function (`def callback(msg, progress)`)\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> def callback(msg, progress):\n" \
    "\t...     print(msg, progress)\n" \
    "\t...\n" \
    "\t>>> ics.set_reflash_callback(callback)\n" \
    "\t>>> \n" 

// _DOC_GET_DEVICE_SETTINGS), meth_get_device_settings, METH_VARARGS, "Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME " and a " VCAN3_SETTINGS_OBJECT_NAME "/" FIRE_SETTINGS_OBJECT_NAME ", exception on error."),
#define _DOC_GET_DEVICE_SETTINGS \
    MODULE_NAME".get_device_settings(device)\n" \
    "\n" \
    "Gets the settings in the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t:class:`"MODULE_NAME"."VCAN3_SETTINGS_OBJECT_NAME"` or :class:`"MODULE_NAME"."FIRE_SETTINGS_OBJECT_NAME"`.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> settings = ics.get_device_settings(device)\n" \
    "\t>>> type(settings)\n" \
    "\t<class 'ics.FireSettings'>\n" \
    "\t>>> \n" 

//_DOC_SET_DEVICE_SETTINGS), "Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME ", " VCAN3_SETTINGS_OBJECT_NAME "/" FIRE_SETTINGS_OBJECT_NAME ", and save to eeprom bool, exception on error."),
#define _DOC_SET_DEVICE_SETTINGS \
    MODULE_NAME".set_device_settings(device, settings)\n" \
    "\n" \
    "Sets the settings in the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tsettings (:class:`"MODULE_NAME"."VCAN3_SETTINGS_OBJECT_NAME"`): :class:`"MODULE_NAME"."VCAN3_SETTINGS_OBJECT_NAME"`\n\n" \
    "\tor:\n\n" \
    "\tsettings (:class:`"MODULE_NAME"."FIRE_SETTINGS_OBJECT_NAME"`): :class:`"MODULE_NAME"."FIRE_SETTINGS_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> settings = ics.get_device_settings(device)\n" \
    "\t>>> type(settings)\n" \
    "\t<class 'ics.FireSettings'>\n" \
    "\t>>> settings.can1.Mode\n" \
    "\t0\n" \
    "\t>>> settings.can1.Mode = 3\n" \
    "\t>>> ics.set_device_settings(device, settings)\n" \
    "\t>>> \n"

//"Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME ", exception on error."
#define _DOC_LOAD_DEFAULT_SETTINGS \
    MODULE_NAME".load_default_settings(device)\n" \
    "\n" \
    "Load the default settings in the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> settings = ics.load_default_settings(device)\n" \
    "\t>>> \n"

#define _DOC_CREATE_NEOVI_RADIO_MESSAGE \
    MODULE_NAME".create_neovi_radio_message(Relay1, Relay2, Relay3, Relay4, Relay5, LED6, LED5, MSB_report_rate, LSB_report_rate, analog_change_report_rate, relay_timeout)\n\n" \
    "Python API only. Generates data bytes for use with neoVI RADI/O CAN Messages\n\n" \
    "Kwargs:\n" \
    "\tRelay1 (boolean): Enable/Disable Relay1\n\n" \
    "\tRelay2 (boolean): Enable/Disable Relay2\n\n" \
    "\tRelay3 (boolean): Enable/Disable Relay3\n\n" \
    "\tRelay4 (boolean): Enable/Disable Relay4\n\n" \
    "\tRelay5 (boolean): Enable/Disable Relay5\n\n" \
    "\tLED5 (boolean): Enable/Disable LED5\n\n" \
    "\tLED6 (boolean): Enable/Disable LED6\n\n" \
    "\tMSB_report_rate (int): MSB Report Rate in ms (0-255)\n\n" \
    "\tLSB_report_rate (int): LSB Report Rate in ms (0-255)\n\n" \
    "\tanalog_change_report_rate (int): Analog change report rate\n\n" \
    "\trelay_timeout (int): Relay Timeout (0-255)*255ms\n\n" \
    "\n" \
    "Returns:\n" \
    "\n" \
    "\tTuple of data bytes for use with :class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"`\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "\t>>> msg = ics.SpyMessage()\n" \
    "\t>>> msg.Data = ics.create_neovi_radio_message(Relay1=True, Relay4=False, LED6=True, MSB_report_rate=10)\n" \
    "\t>>> msg.Data\n" \
    "\t(65, 10, 0, 0, 0)\n"

#define _DOC_COREMINI_START_FBLOCK \
    MODULE_NAME".coremini_start_fblock(device, index)\n" \
    "\n" \
    "Starts a Coremini Function Block at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the function block.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone on Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_start_fblock(device, 1)\n"

#define _DOC_COREMINI_STOP_FBLOCK \
    MODULE_NAME".coremini_stop_fblock(device, index)\n" \
    "\n" \
    "Stops a Coremini Function Block at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the function block.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone on Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_stop_fblock(device, 1)\n"

#define _DOC_COREMINI_GET_FBLOCK_STATUS \
    MODULE_NAME".coremini_get_fblock_status(device, index)\n" \
    "\n" \
    "Gets the status of a Coremini Function Block at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the function block.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone on Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_get_fblock_status(device, 1)\n" \
    "\tTrue\n"

#define _DOC_COREMINI_READ_APP_SIGNAL \
    MODULE_NAME".coremini_read_app_signal(device, index)\n" \
    "\n" \
    "Gets the value of a Coremini application signal at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the application signal.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tint on Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_read_app_signal(device, 1)\n" \
    "\t52\n"

#define _DOC_COREMINI_WRITE_APP_SIGNAL \
    MODULE_NAME".coremini_write_app_signal(device, index, value)\n" \
    "\n" \
    "Sets the value of a Coremini application signal at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the application signal.\n\n" \
    "\tvalue (int): New value of the application signal.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tNone on Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.coremini_write_app_signal(device, 1, 52)\n" \
    "\t>>>\n"

#define _DOC_COREMINI_READ_TX_MESSAGE \
    MODULE_NAME".coremini_read_tx_message(device, index, j1850=False)\n" \
    "\n" \
    "Gets the value of a Coremini Message at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the application signal.\n\n" \
    "\tj1850 (bool): Use :class:`"MODULE_NAME"."SPY_MESSAGE_J1850_OBJECT_NAME"` instead.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t:class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"` Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> msg = ics.coremini_read_tx_message(device, 0)\n"

#define _DOC_COREMINI_READ_RX_MESSAGE \
    MODULE_NAME".coremini_read_rx_message(device, index, j1850=False)\n" \
    "\n" \
    "Gets the value of a Coremini Message at `index` on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tindex (int): Index of the application signal.\n\n" \
    "\tj1850 (bool): Use :class:`"MODULE_NAME"."SPY_MESSAGE_J1850_OBJECT_NAME"` instead.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t:class:`"MODULE_NAME"."SPY_MESSAGE_OBJECT_NAME"` Success.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> msg = ics.coremini_read_tx_message(device, 0)\n"

#define _DOC_COREMINI_WRITE_TX_MESSAGE \
    MODULE_NAME".coremini_write_tx_message(device, index, msg)\n" \
    "TODO"

#define _DOC_COREMINI_WRITE_RX_MESSAGE \
    MODULE_NAME".coremini_write_rx_message(device, index, TODO)\n" \
    "TODO"

#define _DOC_GET_PERFORMANCE_PARAMETERS \
    MODULE_NAME".get_performance_parameters(device)\n" \
    "\n" \
    "Gets the Performance Parameters on `device`.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tTuple on Success: (buffer count, buffer max, overflow count, reserved, reserved, reserved, reserved, reserved)\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.get_performance_parameters(device)\n" \
    "\t(0, 24576, 0, 0, 0, 0, 0, 0)\n"

#define _DOC_VALIDATE_HOBJECT \
    MODULE_NAME".validate_hobject(device)\n" \
    "\n" \
    "Validates the handle is valid for a `device`. Handles are only valid when the device is open.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\tor:\n\n" \
    "\tdevice (int): c style integer handle to the device.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tBoolean: True if valid, false otherwise.\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> ics.validate_hobject(device)\n" \
    "\t1\n" \
    "\t>>> ics.validate_hobject(device._Handle)\n" \
    "\t1\n"

#define _DOC_GET_LAST_API_ERROR \
    MODULE_NAME".get_last_api_error(device)\n" \
    "\n" \
    "Gets the error message from the last API call.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tTuple: (error, description short, description long, severity, restart needed)\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> try:\n" \
    "\t...     msg = ics.coremini_read_tx_message(device, 0)\n" \
    "\t... except ics.RuntimeError as ex:\n" \
    "\t...     print(ex)\n" \
    "\t...     print(ics.get_last_api_error(device))\n" \
    "\t...\n" \
    "\tError: coremini_read_tx_message(): icsneoScriptReadTxMessage() Failed\n" \
    "\t(224, 'Invalid Message Index for script.', 'Invalid Message Index for script.', 16, 0)\n" 

#define _DOC_GET_DLL_VERSION \
    MODULE_NAME".get_dll_version(device)\n" \
    "\n" \
    "Gets the DLL version.\n" \
    "\n" \
    "Args:\n" \
    "\tNone\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tInt: DLL Version\n" \
    "\n" \
    "\t>>> ics.get_dll_version()\n" \
    "\t700\n"

#define _DOC_BASE36ENC \
    MODULE_NAME".base36enc(serial)\n" \
    "\n" \
    "Converts a decimal serial number to base36.\n" \
    "\n" \
    "Args:\n" \
    "\tserial (int): serial number.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tStr: Serial Number\n" \
    "\n" \
    "\t>>> ics.base36enc(device.SerialNumber)\n" \
    "\tCY0024\n"

#define _DOC_GET_SERIAL_NUMBER \
    MODULE_NAME".get_serial_number(device)\n" \
    "\n" \
    "Gets the serial number out of the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tInt: Serial Number Version\n" \
    "\n" \
    "\t>>> ics.get_serial_number(device)\n" \
    "\t53123\n"

#define _DOC_REQUEST_ENTER_SLEEP_MODE \
    MODULE_NAME".request_enter_sleep_mode(device, timeout_ms, mode, reserved_zero)\n" \
    "\n" \
    "Signal neoVI to immediete go to sleep. Currently only supported by FIREVNET/PLASMA.\n" \
    "If using over USB this will likely return true but never cause PLASMA to sleep\n" \
    "since USB insertion keeps it alive.\n" \
    "This API allows Android/Linux applications to invoke power management.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "\ttimeout_ms (int): 16bit word for how long to wait on idle bus before going to sleep. " \
        "If caller does not want to change it pass in 65535 (0xFFFF) and it " \
        "will stay whatever it was set to in explorer/coremini.\n\n" \
    "\n" \
    "\tmode (int): 16bit word for power mode to enter. " \
        "If caller does not want to change it pass in 65535 (0xFFFF) and it " \
        "will stay whatever it was set to in explorer/coremini. " \
        "If it is zero then neoVI will do 'normal sleep'. " \
        "0 - power mode off but calling this function will do 'normal sleep'. " \
        "1 - normal sleep. " \
        "2 - instant sleep. " \
        "3 - comatose sleep.\n\n" \
    "\n" \
    "\treserved_zero (int): Reserved, Keep as zero.\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tBoolean: True on success, False on failure.\n" \
    "\n" \
    "\t>>> ics.request_enter_sleep_mode(device, 1, 0)\n" \
    "\tTrue\n"


#define _DOC_SET_CONTEXT \
    MODULE_NAME".set_context(device)\n" \
    "\n" \
    "Sets the \"context\" of how icsneoFindNeoDevices(Ex) and icsneoOpenNeoDevice(Ex)\n" \
    "function. If the context is 0 (null) than icsneoFindNeoDevices(Ex) will be system\n" \
    "wide, searching USB and other supported computer interfaces. icsneoFindNeoDevices can\n" \
    "then be used to connect to devices found in this manner. If the context is a handle\n" \
    "to connected CAN tool than icsneoFindNeoDevices(Ex) will search a specific CAN bus\n" \
    "for supported IntrepidCS CAN Nodes. Again icsneoOpenNeoDevice(Ex) would be used\n" \
    "create logical connections to found CAN Nodes.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tBoolean: True on success, False on failure.\n" \
    "\n" \
    "\t>>> ics.set_context(device)\n" \
    "\tTrue\n"

#define _DOC_FORCE_FIRMWARE_UPDATE \
    MODULE_NAME".force_firmware_update(device)\n" \
    "\n" \
    "Forces the device to flash firmware.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tBoolean: True on success, False on failure.\n" \
    "\n" \
    "\t>>> ics.force_firmware_update(device)\n" \
    "\tTrue\n"

#define _DOC_FIRMWARE_UPDATE_REQUIRED \
    MODULE_NAME".firmware_update_required(device)\n" \
    "\n" \
    "Determines if the device firmware needs flashing.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\tBoolean: True on success, False on failure.\n" \
    "\n" \
    "\t>>> ics.force_firmware_update(device)\n" \
    "\tTrue\n"

#define _DOC_GET_DLL_FIRMWARE_INFO \
    MODULE_NAME".get_dll_firmware_info(device)\n" \
    "\n" \
    "Returns the DLL firmware info for the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t(:class:`"MODULE_NAME"."API_FIRMWARE_INFO_OBJECT_NAME"`)\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> info = ics.get_dll_firmware_info(device)\n" \
    "\t>>> info.iAppMajor\n" \
    "\t7\n" \
    "\t>>> info.iAppMinor\n" \
    "\t55\n" \
    "\t>>>\n"

#define _DOC_GET_HW_FIRMWARE_INFO \
    MODULE_NAME".get_hw_firmware_info(device)\n" \
    "\n" \
    "Returns the device firmware info for the device.\n" \
    "\n" \
    "Args:\n" \
    "\tdevice (:class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`): :class:`"MODULE_NAME"."NEO_DEVICE_OBJECT_NAME"`\n\n" \
    "\n" \
    "Raises:\n" \
    "\t:class:`"MODULE_NAME".RuntimeError`\n" \
    "\n" \
    "Returns:\n" \
    "\t(:class:`"MODULE_NAME"."API_FIRMWARE_INFO_OBJECT_NAME"`)\n" \
    "\n" \
    "\t>>> device = ics.open_device()\n" \
    "\t>>> info = ics.get_hw_firmware_info(device)\n" \
    "\t>>> info.iAppMajor\n" \
    "\t7\n" \
    "\t>>> info.iAppMinor\n" \
    "\t55\n" \
    "\t>>>\n"

static PyMethodDef IcsMethods[] = {
    _EZ_ICS_STRUCT_METHOD("find_devices", "FindNeoDevices", (PyCFunction)meth_find_devices, METH_VARARGS | METH_KEYWORDS, _DOC_FIND_DEVICES),
    _EZ_ICS_STRUCT_METHOD("open_device", "OpenNeoDevice", (PyCFunction)meth_open_device, METH_VARARGS | METH_KEYWORDS, _DOC_OPEN_DEVICES),
    _EZ_ICS_STRUCT_METHOD("close_device", "ClosePort", meth_close_device, METH_VARARGS, _DOC_CLOSE_DEVICES),
    _EZ_ICS_STRUCT_METHOD("get_rtc", "GetRTC", meth_get_rtc, METH_VARARGS, _DOC_GET_RTC),
    _EZ_ICS_STRUCT_METHOD("set_rtc", "SetRTC", meth_set_rtc, METH_VARARGS, _DOC_SET_RTC),
    _EZ_ICS_STRUCT_METHOD("coremini_load", "ScriptLoad", meth_coremini_load, METH_VARARGS, _DOC_COREMINI_LOAD),
    _EZ_ICS_STRUCT_METHOD("coremini_start", "ScriptStart", meth_coremini_start, METH_VARARGS, _DOC_COREMINI_START),
    _EZ_ICS_STRUCT_METHOD("coremini_stop", "ScriptStop", meth_coremini_stop, METH_VARARGS, _DOC_COREMINI_STOP),
    _EZ_ICS_STRUCT_METHOD("coremini_clear", "ScriptClear", meth_coremini_clear, METH_VARARGS, _DOC_COREMINI_CLEAR),
    _EZ_ICS_STRUCT_METHOD("coremini_get_status", "ScriptGetScriptStatus", meth_coremini_get_status, METH_VARARGS, _DOC_COREMINI_GET_STATUS),
    _EZ_ICS_STRUCT_METHOD("transmit_messages", "TxMessages", meth_transmit_messages, METH_VARARGS, _DOC_TRANSMIT_MESSAGES),
    _EZ_ICS_STRUCT_METHOD("get_messages", "GetMessages", meth_get_messages, METH_VARARGS, _DOC_GET_MESSAGES),
    _EZ_ICS_STRUCT_METHOD("get_script_status", "icsneoScriptGetScriptStatusEx", meth_get_script_status, METH_VARARGS, "Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME ", exception on error. Returns a list of values of what ulParameters would hold"),
    _EZ_ICS_STRUCT_METHOD("get_error_messages", "GetErrorMessages", meth_get_error_messages, METH_VARARGS, _DOC_GET_ERROR_MESSAGES),
#ifdef _USE_INTERNAL_HEADER_
    _EZ_ICS_STRUCT_METHOD("flash_devices", "FlashDevice2", meth_flash_devices, METH_VARARGS, "int _stdcall FlashDevice2()"),
#endif
    _EZ_ICS_STRUCT_METHOD("set_reflash_callback", "SetReflashDisplayCallback", meth_set_reflash_callback, METH_VARARGS, _DOC_SET_REFLASH_CALLBACK),
    _EZ_ICS_STRUCT_METHOD("get_device_settings", "icsneoGetFireSettings", meth_get_device_settings, METH_VARARGS, _DOC_GET_DEVICE_SETTINGS),
    _EZ_ICS_STRUCT_METHOD_MULTIPLE("get_device_settings", "icsneoGetVCAN3Settings", meth_get_device_settings, METH_VARARGS, _DOC_GET_DEVICE_SETTINGS),
    _EZ_ICS_STRUCT_METHOD("set_device_settings", "icsneoSetFireSettings", meth_set_device_settings, METH_VARARGS, _DOC_SET_DEVICE_SETTINGS),
    _EZ_ICS_STRUCT_METHOD_MULTIPLE("set_device_settings", "icsneoSetVCAN3Settings", meth_set_device_settings, METH_VARARGS, _DOC_SET_DEVICE_SETTINGS),
    _EZ_ICS_STRUCT_METHOD("load_default_settings", "icsneoLoadDefaultSettings", meth_load_default_settings, METH_VARARGS, _DOC_LOAD_DEFAULT_SETTINGS),
    //_EZ_ICS_STRUCT_METHOD("spy_message_to_j1850", METH_spy_message_to_j1850, METH_VARARGS, "Accepts a " MODULE_NAME "." SPY_MESSAGE_OBJECT_NAME ", and returns a " MODULE_NAME "." SPY_MESSAGE_J1850_OBJECT_NAME ". Exception on error."),
    _EZ_ICS_STRUCT_METHOD("read_sdcard", "icsneoReadSDCard", meth_read_sdcard, METH_VARARGS, "icsneoReadSDCard(), Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME " and sector index. Returns a bytearray of 512 bytes max. Exception on error."),
    _EZ_ICS_STRUCT_METHOD("write_sdcard", "icsneoWriteSDCard", meth_write_sdcard, METH_VARARGS, "icsneoReadSDCard(), Accepts a " MODULE_NAME "." NEO_DEVICE_OBJECT_NAME ", sector index, and a bytearray of 512 bytes. Exception on error."),
    {"create_neovi_radio_message", (PyCFunction)meth_create_neovi_radio_message, METH_VARARGS | METH_KEYWORDS, _DOC_CREATE_NEOVI_RADIO_MESSAGE},
    _EZ_ICS_STRUCT_METHOD("coremini_start_fblock", "ScriptStartFBlock", meth_coremini_start_fblock, METH_VARARGS, _DOC_COREMINI_START_FBLOCK),
    _EZ_ICS_STRUCT_METHOD("coremini_stop_fblock", "ScriptStopFBlock", meth_coremini_stop_fblock, METH_VARARGS, _DOC_COREMINI_STOP_FBLOCK),
    _EZ_ICS_STRUCT_METHOD("coremini_get_fblock_status", "ScriptGetFBlockStatus", meth_coremini_get_fblock_status, METH_VARARGS, _DOC_COREMINI_GET_FBLOCK_STATUS),
    _EZ_ICS_STRUCT_METHOD("coremini_read_app_signal", "ScriptReadAppSignal", meth_coremini_read_app_signal, METH_VARARGS, _DOC_COREMINI_READ_APP_SIGNAL),
    _EZ_ICS_STRUCT_METHOD("coremini_write_app_signal", "ScriptWriteAppSignal", meth_coremini_write_app_signal, METH_VARARGS, _DOC_COREMINI_WRITE_APP_SIGNAL),
    _EZ_ICS_STRUCT_METHOD("coremini_read_tx_message", "ScriptReadTxMessage", meth_coremini_read_tx_message, METH_VARARGS, _DOC_COREMINI_READ_TX_MESSAGE),
    _EZ_ICS_STRUCT_METHOD("coremini_read_rx_message", "ScriptReadRxMessage", meth_coremini_read_rx_message, METH_VARARGS, _DOC_COREMINI_READ_RX_MESSAGE),
    _EZ_ICS_STRUCT_METHOD("coremini_write_tx_message", "ScriptWriteTxMessage", meth_coremini_write_tx_message, METH_VARARGS, _DOC_COREMINI_WRITE_TX_MESSAGE),
    _EZ_ICS_STRUCT_METHOD("coremini_write_rx_message", "ScriptWriteRxMessage", meth_coremini_write_rx_message, METH_VARARGS, _DOC_COREMINI_WRITE_RX_MESSAGE),
    _EZ_ICS_STRUCT_METHOD("get_performance_parameters", "GetPerformanceParameters", meth_get_performance_parameters, METH_VARARGS, _DOC_GET_PERFORMANCE_PARAMETERS),
    _EZ_ICS_STRUCT_METHOD("validate_hobject", "ValidateHObject", meth_validate_hobject, METH_VARARGS, _DOC_VALIDATE_HOBJECT),
    _EZ_ICS_STRUCT_METHOD("get_last_api_error", "GetLastAPIError", meth_get_last_api_error, METH_VARARGS, _DOC_GET_LAST_API_ERROR),
    _EZ_ICS_STRUCT_METHOD("get_dll_version", "GetDLLVersion", meth_get_dll_version, METH_NOARGS, _DOC_GET_DLL_VERSION),
    _EZ_ICS_STRUCT_METHOD("get_serial_number", "GetSerialNumber", meth_get_serial_number, METH_VARARGS, _DOC_GET_SERIAL_NUMBER),
    _EZ_ICS_STRUCT_METHOD("get_hw_firmware_info", "GetHWFirmwareInfo", meth_get_hw_firmware_info, METH_VARARGS, _DOC_GET_HW_FIRMWARE_INFO),
    _EZ_ICS_STRUCT_METHOD("request_enter_sleep_mode", "RequestEnterSleepMode", meth_request_enter_sleep_mode, METH_VARARGS, _DOC_REQUEST_ENTER_SLEEP_MODE),
    {"base36enc", (PyCFunction)meth_base36enc, METH_VARARGS | METH_KEYWORDS, _DOC_BASE36ENC},
    _EZ_ICS_STRUCT_METHOD("set_context", "icsneoSetContext", meth_set_context, METH_VARARGS, _DOC_SET_CONTEXT),
    _EZ_ICS_STRUCT_METHOD("force_firmware_update", "icsneoForceFirmwareUpdate", meth_force_firmware_update, METH_VARARGS, _DOC_FORCE_FIRMWARE_UPDATE),
    _EZ_ICS_STRUCT_METHOD("firmware_update_required", "icsneoFirmwareUpdateRequired", meth_firmware_update_required, METH_VARARGS, _DOC_FIRMWARE_UPDATE_REQUIRED),
    _EZ_ICS_STRUCT_METHOD("get_dll_firmware_info", "icsneoGetDLLFirmwareInfo", meth_get_dll_firmware_info, METH_VARARGS, _DOC_GET_DLL_FIRMWARE_INFO),

    
    { NULL, NULL, 0, NULL }
};

#endif // _METHODS_H_
