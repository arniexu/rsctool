/**
 * @file Rsc2CApi.h
 */
#ifndef RSC2CAPI_H
#define RSC2CAPI_H

#ifdef RSC2CAPI_EXPORTS
/* #define RSC2CAPI __declspec(dllexport) */
#define RSC2CAPI 
#else
#define RSC2CAPI __declspec(dllimport)
#endif

#define RSC2CALL _stdcall

/**
 * @defgroup EnumGroup Enumerations
 * @{
 */

/** 
 * Signal Identifiers. 
 *
 * Signals can either be referred to by their
 * assigned names or generic names. The assignments are valid for RSC2 units
 * with their "squid pod" attached to the SUT in a standard configuration.
 * If not using a standard configuration, the signals can be treated as 
 * general purpose and their generic names can be used instead in the API.
 * There's no functional difference between using the assigned name or the 
 * generic name.
 */
typedef enum  
{
	RSC2_ID_OUT_1 = 0,				/**< Generic name for RSC2_ID_FPBUT_PWR. */
	RSC2_ID_FPBUT_PWR = 0,			/**< SUT's power button signal. */
	RSC2_ID_OUT_2 = 1,				/**< Generic name for RSC2_ID_FPBUT_RESET. */
	RSC2_ID_FPBUT_RESET = 1,		/**< SUT's reset button signal. */
	RSC2_ID_OUT_3 = 2,				/**< Generic name for RSC2_ID_FPBUT_ID. */
	RSC2_ID_FPBUT_ID = 2,			/**< SUT's ID button signal. */
	RSC2_ID_OUT_4 = 3,				/**< Generic name for RSC2_ID_JMP_MFG_MODE. */
	RSC2_ID_JMP_MFG_MODE = 3,		/**< SUT's Manufacturing Mode jumper. */
	RSC2_ID_OUT_5 = 4,				/**< Generic name for RSC2_ID_JMP_CLR_CMOS. */
	RSC2_ID_JMP_CLR_CMOS = 4,		/**< SUT's CMOS Clear jumper. */
	RSC2_ID_OUT_6 = 5,				/**< Generic name for RSC2_ID_JMP_BMC_FRC_UPD. */
	RSC2_ID_JMP_BMC_FRC_UPD = 5,	/**< SUT's BMC Force Update jumper. */
	RSC2_ID_OUT_7 = 6,				/**< Generic name for RSC2_ID_JMP_BIOS_RECOVERY. */
	RSC2_ID_JMP_BIOS_RECOVERY = 6,	/**< SUT's BIOS Recovery jumper. */
	RSC2_ID_OUT_8 = 7,				/**< Generic name for RSC2_ID_OUT_AUX_A. */
	RSC2_ID_OUT_AUX_A = 7,			/**< General purpose output AUX A. */
	RSC2_ID_OUT_9 = 8,				/**< Generic name for RSC2_ID_OUT_AUX_B. */
	RSC2_ID_OUT_AUX_B = 8,			/**< General purpose output AUX B. */
	RSC2_ID_OUT_10 = 9,				/**< Generic name for RSC2_ID_OUT_AUX_C. */
	RSC2_ID_OUT_AUX_C = 9,			/**< General purpose output AUX C. */

	RSC2_ID_INP_1 = 10,				/**< Generic name for RSC2_ID_LED_PWR. */
	RSC2_ID_LED_PWR = 10,			/**< SUT's power LED. */
	RSC2_ID_INP_2 = 11,				/**< Generic name for RSC2_ID_LED_STATUS_GREEN. */
	RSC2_ID_LED_STATUS_GREEN = 11,	/**< SUT's green status LED. */
	RSC2_ID_INP_3 = 12,				/**< Generic name for RSC2_ID_LED_STATUS_AMBER. */
	RSC2_ID_LED_STATUS_AMBER = 12,	/**< SUT's amber status LED. */
	RSC2_ID_INP_4 = 13,				/**< Generic name for RSC2_ID_LED_ID_BLUE. */
	RSC2_ID_LED_ID_BLUE = 13,		/**< SUT's blue ID LED. */
	RSC2_ID_INP_5 = 14,				/**< Generic name for RSC2_ID_INP_AUX_A. */
	RSC2_ID_INP_AUX_A = 14,			/**< General purpose output AUX A. */
	RSC2_ID_INP_6 = 15,				/**< Generic name for RSC2_ID_INP_AUX_B. */
	RSC2_ID_INP_AUX_B = 15,			/**< General purpose output AUX B. */
	RSC2_ID_AC_1 = 16,				/**< The RSC2 unit's AC output port 1. */
	RSC2_ID_AC_2 = 17				/**< The RSC2 unit's AC output port 2. */
} Rsc2_SignalID;

/** 
 * Signal States. 
 *
 * The states a signal can be in depending on the signal's type. The enum items
 * share the same two values (1 or 0) and are therefore synonymous with each
 * other. They are provided this way so the developer can write code that is
 * semantically intuitive for other developers to read. For instance, when 
 * using a jumper, it's states would be RSC2_JMP_ENABLED/DISABLED (1/0); or an 
 * AC port would have states RSC2_AC_ON/OFF (also 1/0). 
 */
typedef enum 
{
	/* Generic */
	RSC2_SIG_ASSERTED = 1,		/**< Generic asserted state for any signal. */
	RSC2_SIG_DEASSERTED = 0,	/**< Generic deasserted state for any signal. */

	/* For jumpers */
	RSC2_JMP_ENABLED = 1,		/**< Jumper enabled state. */
	RSC2_JMP_DISABLED = 0,		/**< Jumper disabled state. */

	/* For buttons */
	RSC2_BUTTON_PRESSED = 1,	/**< Button pressed state. */
	RSC2_BUTTON_RELEASED = 0,	/**< Button released (not pressed) state. */

	/* For AC ports */
	RSC2_AC_ON = 1,				/**< AC port (RSC2 back panel) on. */
	RSC2_AC_OFF = 0,			/**< AC port off. */

	/* For LEDs */
	RSC2_LED_ON = 1,			/**< LED on (lit up) state. */
	RSC2_LED_OFF = 0			/**< LED off (dark) state. */
} Rsc2_SignalState;

/** 
 * Signal Type. 
 *
 * A signal can be general purpose (GPIO), or a jumper, button, AC port, or LED.
 */
typedef enum 
{
	RSC2_GPIO,		/**< A GPIO Signal. */
	RSC2_JUMPER,	/**< A Jumper. */
	RSC2_BUTTON,	/**< A Button. */
	RSC2_AC_PORT,	/**< An AC Port. */
	RSC2_LED		/**< An LED. */
} Rsc2_SignalType;

/**
 * Signal Assertion Type. 
 *
 * This applies to the internals of the library. The assertion type of a 
 * signal determines how a logic 1 or 0 is in interpreted. This affects 
 * commands that report signal state. Signal state is a cooked value based 
 * on the raw logical value of a signal and its assertion type.
 */
typedef enum 
{
	RSC2_ACTIVE_HIGH = 1,	/**< Voltage high indicates logical 1 value. */
	RSC2_ACTIVE_LOW = 0		/**< Voltage low indicates logical 1 value. */
} Rsc2_AssertionType;

/**
 * USB MUX State. 
 *
 * The USB port on the front of the RSC2 box can host a drive that can be 
 * switched between the SUT and the PC connected to the RSC2 box. This is
 * useful for things like putting a startup batch file on the drive while
 * switched to the RSC2 host, then switching the drive to the SUT and 
 * booting it.
 */
typedef enum 
{
	RSC2_MUX_STATE_UNKNOWN = 0,	/**< Unable to determine the MUX's state. */
	RSC2_MUX_TO_HOST,			/**< The USB port is visible to the RSC2 host. */
	RSC2_MUX_TO_SUT,			/**< The USB port is visible to the SUT. */
	RSC2_MUX_DISCONNECTED,		/**< The USB port is disconnected. */
	RSC2_MUX_DISABLED			/**< The USB port is disabled. */
} Rsc2_UsbMuxState;

/** 
 * RSC2 Unit's Status. 
 */
typedef enum 
{
	RSC2_STAT_UNKNOWN = 0,		/**< Unable to determine the RSC2 unit's status. */
	RSC2_STAT_AVAILABLE,		/**< The RSC2 unit is available for use. */
	RSC2_STAT_LOCKED,			/**< Somebody currently has claim to the unit. */
	RSC2_STAT_OFFLINE,			/**< The RSC2 unit is offline (it may be unplugged). */
	RSC2_STAT_UPDATE_IN_PROG	/**< The unit is having its firmware updated. */
} Rsc2_BoxStatus;

/**
 * Power Cycle Type.
 *  
 * Power cycle type applies to automated power cycling implemented within the 
 * RSC2's firmware. The RSC2 unit can be set up to cycle AC, DC, or AC and DC
 * power to the SUT. No further interaction between the RSC2 GUI or API needs 
 * to occur for the cycling to progress. The status of the cycling can then
 * be polled by the API or GUI.
 */
typedef enum
{
	RSC2_PWRCYC_AC = 1,		/**< Cycle just the AC ports of the RSC2 unit. */
	RSC2_PWRCYC_DC = 2,		/**< Cycle the SUT's DC power by pressing its power button. */
	RSC2_PWRCYC_AC_DC = 3	/**< Cycle both AC and DC power to the SUT. */
} Rsc2_PwrCycleType;

/**
 * Error Codes. 
 * 
 * Typically, the only commands that will fail are ones that require real time
 * transfer of data between the RSC2 server process and the client application.
 * Many command cache information from the server process and won't fail.
 * The commands in the API that can fail return a value from this enumeration.
 */
typedef enum 
{
	RSC2_SUCCESS						= 0,	/**< Command successful. */
	RSC2_ERR_UNSPECIFIED				= -1,	/**< Unspecified failure. */
	RSC2_ERR_REMOTE_OBJ_DISCONNECTED	= -2,	/**< The RSC2 server process 
												     is likely unreachable due 
													 to a network issue. */ 
	RSC2_ERR_BOX_LOCKED					= -3,	/**< The command failed because
												     the box has been locked. */
	RSC2_ERR_COMMAND_FAILED				= -4,	/**< Command failed. */
	RSC2_ERR_INVALID_OBJ_REF			= -5,	/**< An object pointer passed to
												     a function wasn't valid. */
	RSC2_ERR_NOT_IMPLEMENTED_YET		= -6	/**< The command called is not
												     fully implemented. */
} Rsc2_Result;

/** @} end EnumGroup */

/* Objects */
typedef struct Rsc2_Object	Rsc2_Object;	/**< Base object class. */
typedef struct Rsc2_Host	Rsc2_Host;		/**< Represents a system hosting an RSC2 unit. */
typedef struct Rsc2_Box		Rsc2_Box;		/**< Represents an RSC2 unit. */
typedef struct Rsc2_Signal	Rsc2_Signal;	/**< Represents a signal of an RSC2 unit or SUT. */

/* Listeners */

/**
 * Host Event Listener.
 * 
 * A struct containing user/programmer supplied callback functions that are 
 * invoked whenever an event of interest happens at the host.
 */
typedef struct 
{
	/** 
	 * Handler invoked when an RSC2 unit is attached to the host.
	 * @param host The host event source.
	 * @param box The box that was attached from this host.
	 */
	void (*boxAdded)	(Rsc2_Host* host, Rsc2_Box* box);

	/** 
	 * Handler invoked when an RSC2 unit is detached from the host. 
	 * @param host The host event source.
	 * @param box The box that was detached from this host.
	 */
	void (*boxRemoved)	(Rsc2_Host* host, Rsc2_Box* box);
	
	/** 
	 * Handler invoked when the host goes offline. 
	 * @param host The host that went offline.
	 */
	void (*hostOffline)	(Rsc2_Host* host);

	/** 
	 * Handler invoked when the host comes online. 
	 * @param host The host that came online.
	 */
	void (*hostOnline)	(Rsc2_Host* host);
} Rsc2_HostListener;

/**
 * Box Listener.
 * 
 * A struct containing user/programmer supplied callbacks that are invoked 
 * when events of interest happen at an RSC2 unit.
 */
typedef struct 
{
	/** 
	 * Handler invoked when a signal changes state.
	 * @see Rsc2BoxStatus.
	 * @param sig The signal that changed state.
	 */
	void (*sigStateChanged)			(Rsc2_Signal* sig);

	/**
	 * Handler invoked when a signal's label changes.
	 * @param sig The relevant signal.
	 */
	void (*sigLabelChanged)			(Rsc2_Signal* sig);

	/**
	 * Handler invoked when a box's status changes.
	 * @param box The box whose status changed.
	 */
	void (*boxStatusChanged)		(Rsc2_Box* box);

	/**
	 * Handler invoked when the lock holder for a box changes.
	 * @param box The box that has been locked/unlocked.
	 */
	void (*lockHolderChanged)		(Rsc2_Box* box);

	/**
	 * Handler invoked when a box's label changes.
	 * @param box The box that has the label that changed.
	 */
	void (*userLabelChanged)		(Rsc2_Box* box);

	/**
	 * Handler invoked when the KVM address for a box changes.
	 * @param box The box for which the KVM address changed.
	 */
	void (*kvmAddressChanged)		(Rsc2_Box* box);

	/**
	 * Handler invoked when the USB MUX changes position.
	 * @param box The box for which the USB MUX changed position.
	 */
	void (*usbMuxChanged)			(Rsc2_Box* box);
} Rsc2_BoxListener;

/* Other structs */

/**
 * Symbol Record.
 * Certain API functions that were created to facilitate integration with 
 * scripting languages return arrays of this type. This struct contains the
 * textual name of a symbol found in the C API and its associated numeric
 * value.
 */
typedef struct
{
	char* name;	/**< The name of the symbol as found in the C API in this header. */
	int value;	/**< The numeric value of the symbol. */
} Rsc2_SymRec;

/**
 * Power Cycle Status.
 * For automated power cycling driven by the RSC2 unit, the status of that
 * cycling can be polled/queried. This structure reports information about
 * power cycling that is in progress.
 */
typedef struct
{
	Rsc2_PwrCycleType type;

    unsigned short numCycles;
    unsigned short continueWaitTimeSecs;
    unsigned short offTimeMSecs;

	struct 
	{
		unsigned char isCyclingInProgress : 1;
		unsigned char isPhaseErrorDetected : 1;
		unsigned char isTimedOutWaitingForContinue : 1;
	};
} Rsc2_PwrCycleStatus;

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @addtogroup MiscGroup Miscellaneous Functions
	 * @{
	 */

	/**
	 * Initializes the library. 
	 * This must be called before other library functions can be used.
	 *
	 * @return 0 on success and -1 on failure.
	 */
	RSC2CAPI int RSC2CALL Rsc2_Init();

	/**
	 * Gets the error message from the last failed command. 
	 * This function is threadsafe, you can retrieve the last error message
	 * from the last failed command in the same thread regardless if another
	 * thread executed a command that failed.
	 * 
	 * @param buf The buffer to read the error message into.
	 * @param bufSize The size of the buffer to read into.
	 * @return The length in characters of the last error message, or 0 if 
	 *         no error string is available for reading.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetLastErrorMessage(char* buf, int bufSize);

	/** @} end MiscGroup */

	/** 
	 * @addtogroup ObjectGroup Object Functions 
	 * @{
	 */

	/**
	 * Associates anything you want with the Rsc2_Object instance. 
	 * This function can be used to tack a structure, string, value, etc. onto 
	 * the Rsc2_Object for whatever purpose the developer chooses. This can be 
	 * retrieved from the object later using Rsc2_GetObjectClientData.
	 * 
	 * @param obj The Rsc2_Object to attach something to.
	 * @param clientData The <whatever> to attach to the Rsc2_Object.
	 */
	RSC2CAPI void RSC2CALL Rsc2_SetObjectClientData(Rsc2_Object* obj, void* clientData);

	/**
	 * Retrieves whatever has been attached to the Rsc2_Object by the 
	 * developer.
	 * 
	 * @param obj The object to retrieve the client data from.
	 * @return The client data that was attached to the object.
	 */
	RSC2CAPI void* RSC2CALL Rsc2_GetObjectClientData(Rsc2_Object* obj);

	/* Object commands useful for type checking in scripting language wrappers */

	/**
	 * Checks the pointer to determine if it points to a valid object.
	 * This is useful when integrating the C API with scripting languages.
	 * 
	 * @param obj The pointer to check.
	 * @return 1 if the pointer points to a valid object, 0 otherwise.
	 */
	RSC2CAPI int RSC2CALL Rsc2_IsValidObjPtr(void* obj);

	/**
	 * Checks the pointer to determine if it points to a valid Host object.
	 * This is useful when integrating the C API with scripting languages.
	 * 
	 * @param obj The pointer to check.
	 * @return 1 if the pointer points to a valid object, 0 otherwise.
	 */
	RSC2CAPI int RSC2CALL Rsc2_IsValidHostPtr(void* obj);

	/**
	 * Checks the pointer to determine if it points to a valid Box object.
	 * This is useful when integrating the C API with scripting languages.
	 * 
	 * @param obj The pointer to check.
	 * @return 1 if the pointer points to a valid object, 0 otherwise.
	 */
	RSC2CAPI int RSC2CALL Rsc2_IsValidBoxPtr(void* obj);

	/**
	 * Checks the pointer to determine if it points to a valid Signal object.
	 * This is useful when integrating the C API with scripting languages.
	 * 
	 * @param obj The pointer to check.
	 * @return 1 if the pointer points to a valid object, 0 otherwise.
	 */
	RSC2CAPI int RSC2CALL Rsc2_IsValidSignalPtr(void* obj);

	/** @} end ObjectGroup */

	/**
	 * @addtogroup HostGroup Host Functions 
	 * @{
	 */

	/**
	 * Opens a connection to a host. A host system is one that is connected to
	 * one or more RSC2 units. 
	 * 
	 * @param host The IP or system name to connect to.
	 * @return A pointer to the Host object representing the remote system.
	 */
	RSC2CAPI Rsc2_Host*	RSC2CALL Rsc2_ConnectToHost(const char* host);

	/**
	 * Attaches a listener to a host object. A listener is a struct with
	 * pointers to functions defined by you, the developer. These functions 
	 * are called when events of interest occur at the host; for instance, 
	 * when an RSC2 unit is attached or removed from the host system. There
	 * can only be one listener attached to the host.
	 * @see Rsc2_HostListener
	 *
	 * @param host The host to attach a listener to.
	 * @param listener The event listener.
	 */
	RSC2CAPI void RSC2CALL Rsc2_AttachHostListener(Rsc2_Host* host, Rsc2_HostListener* listener);

	/**
	 * Detaches a listener from the host.
	 */
	RSC2CAPI void RSC2CALL Rsc2_DetachHostListener(Rsc2_Host* host, Rsc2_HostListener* listener);

	/**
	 * Returns the number of RSC2 units attached to the host system.
	 *
	 * @param host The host to get this information from.
	 * @return The number of boxes attached to the host, or 0 if none.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetNumBoxes(Rsc2_Host* host);

	/**
	 * Obtains a box object from the given host. The box object represents an
	 * RSC2 unit.
	 * 
	 * @param host The host to get the box from.
	 * @param index The index of the box to retrieve.
	 * @return The box object requested.
	 */
	RSC2CAPI Rsc2_Box* RSC2CALL Rsc2_GetBox(Rsc2_Host* host, int index);

	/** @} end HostGroup Host Functions */

	/** 
	 * @defgroup BoxGroup Box Functions
	 * @{
	 */

	/**
	 * Attaches an event listener to the box. A listener is a collection of 
	 * pointers to functions defined by you, the developer. They will be 
	 * called when events of interest occur in the box. For instance, when
	 * the state of a signal changes. Only one listener per box is supported
	 * currently by the C API.
	 * @see Rsc2_BoxListener
	 * 
	 * @param box The box to attach a listener to.
	 * @param listener The event listener.
	 */
	RSC2CAPI void RSC2CALL Rsc2_AttachBoxListener(Rsc2_Box* box, Rsc2_BoxListener* listener);

	/**
	 * Removes a listener from the given box.
	 * 
	 * @param box The box to remove the listener from.
	 * @param listener The listener to remove.
	 */
	RSC2CAPI void RSC2CALL Rsc2_DetachBoxListener(Rsc2_Box* box, Rsc2_BoxListener* listener);

	/**
	 * Sets the label of a box. A label is just a string that is stored by the 
	 * box that can be retrieved using Rsc2_GetUserLabel(). The label can be used to 
	 * identify the box, or give some brief info about the box visible to other 
	 * users.
	 * 
	 * @param box The box to set the label for.
	 * @param label The label to assign to the box.
	 * @return RSC2_SUCCESS on success, or another error code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_SetUserLabel(Rsc2_Box* box, const char* label);

	/**
	 * Sets the KVM address of the RSC2 unit. The RSC2 unit does not use the
	 * KVM address for anything. This property is just a label assigned to a box
	 * that the GUI or other applications can retrieve. The KVM address will 
	 * have the IP or host name of the KVM unit associated with the RSC2 unit.
	 * The KVM and RSC2 units are separate pieces of hardware with no direct
	 * interactivity.
	 *
	 * @param box The box to set the KVM address property of.
	 * @param address The IP or host name of the KVM unit.
	 * @return RSC2_SUCCESS on success, or another error code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_SetKvmAddress(Rsc2_Box* box, const char* address);

	/**
	 * Locks the RSC2 unit for exclusive control by one user. This is not
	 * really a security feature - basically it's a mechanism to inform other
	 * users that the box is in use. Other users can take over the lock anyway,
	 * but will be prompted by the GUI to let them know they could be 
	 * interrupting someone else's work. Using the C API, it would be a good
	 * idea to determine if the box has been locked before performing any 
	 * operations with it. Rsc2_GetOnlineStatus() can be used for this purpose.
	 *
	 * @param box The box to lock.
	 * @param contactString A string with information about who to contact
	 *        (and how) to find out if the RSC2 is still in use, or if you can
	 *        free the lock and use it.
	 * @return RSC2_SUCCESS on success, or another error code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_LockBox(Rsc2_Box* box, const char* contactString);

	/**
	 * Removes the lock from a box. If the Rsc2_BoxStatus was RSC2_STAT_LOCKED,
	 * then it will be set to RSC2_STAT_AVAILABLE.
	 *
	 * @param box The box to unlock.
	 * @return RSC2_SUCCESS on success, or another error code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_UnlockBox(Rsc2_Box* box);

	/**
	 * Switches the RSC2's front USB port between the host and the target.
	 * A USB key drive can be attached to the RSC2 and the user can put 
	 * files on it while its MUX is switched to the host; then the key
	 * can be switched to the target. The target will then have access to
	 * these files. One use is to put files on the key, switching it to the
	 * target, then rebooting the target which will then execute the 
	 * startup batch file on the key.
	 * 
	 * @param box The box that has the USB port to switch.
	 * @param state The state to set the USB MUX to.
	 * @return RSC2_SUCCESS on success, or another error code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_SetUsbMux(Rsc2_Box* box, Rsc2_UsbMuxState state);

	/**
	 * Gets the specified signal object from a box. The signal object 
	 * represents a button, jumper, LED, or AC port.
	 * 
	 * @param box The box to retrieve the signal object from.
	 * @param signalId The identifier of the signal (#Rsc2_SignalID).
	 * @return The requested signal object, or NULL if it doesn't exist.
	 */
	RSC2CAPI Rsc2_Signal* RSC2CALL Rsc2_GetSignal(Rsc2_Box* box, Rsc2_SignalID signalId);

	/**
	 * Retrieves a description of the box device. Currently only RSC2 units are
	 * supported, but if others ever are, they'd report different descriptions.
	 *
	 * @param box The box to get the description for.
	 * @param buf The buffer to read the description into.
	 * @return The character length of the description string.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetDescription(Rsc2_Box* box, char* buf, int size);

	/**
	 * Retrieves the label assigned to the device. The label is simply some
	 * textual information, or a name, assigned to an RSC2 box for users to
	 * identify it or know some basic information about it.
	 *
	 * @param box The box to get its label from.
	 * @param buf The buffer to read the label into.
	 * @param size The size of the buffer.
	 * @return The character length of the label.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetUserLabel(Rsc2_Box* box, char* buf, int size);

	/**
	 * Retrieves the KVM address assigned to the RSC2 box. The KVM address 
	 * has no other purpose than to associate which KVM on the network is
	 * attached to the same target as the RSC2 box queried. Once you have
	 * the address, you can open a browser and connect to the KVM device 
	 * connected to the same target as the RSC2. Users need to update this
	 * when they change the set up in the lab.
	 *
	 * @param box The box to get the KVM address from.
	 * @param buf The buffer to read the address in to.
	 * @param size The size of the buffer.
	 * @return The character length of the address string.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetKvmAddress(Rsc2_Box* box, char* buf, int size);

	/**
	 * Gets the name of the user or system holding the lock to the RSC2 box.
	 * Use Rsc2_GetOnlineStatus() to determine if the box is locked. 
	 * If the device is already locked, one can 
	 * query the contact string of the box and contact the lock holder to see
	 * if they can take over the system. Locks can be easily overridden by
	 * other users. The lock is only a convention to deter users from 
	 * unknowningly clobbering each other's work.
	 *
	 * @param box The box to get the lock holder name from.
	 * @param buf The buffer to read the name into.
	 * @param size The size of the buffer.
	 * @return The character length of the string.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetLockHolder(Rsc2_Box* box, char* buf, int size);

	/**
	 * Returns the status (#Rsc2_BoxStatus) of the box.
	 *
	 * @param box The box to get the status of.
	 * @return The status of the box.
	 */
	RSC2CAPI Rsc2_BoxStatus RSC2CALL Rsc2_GetOnlineStatus(Rsc2_Box* box);

	/**
	 * Returns the current position (#Rsc2_UsbMuxState) of the USB MUX.
	 *
	 * @param box The box to get the MUX postion from.
	 * @return The current position of the MUX.
	 */
	RSC2CAPI Rsc2_UsbMuxState RSC2CALL Rsc2_GetUsbMuxState(Rsc2_Box* box);

	/** @} end BoxGroup */

	/**
	 * @defgroup PwrCycGroup Power Cycling Functions 
	 * @{
	 */

	/**
	 * Sets up the RSC2 box to do automated power cycling. This type of
	 * power cycling is implemented in the RSC2's firmware - the API doesn't
	 * need to issue commands after that point to drive the cycling, but can
	 * poll the status of the cycling.
	 *
	 * @param box The box to do the power cycling.
	 * @param cycleType The type of cycling (#Rsc2_PwrCycleType) to perform 
	 *		  (AC, DC or both).
	 * @param cycleCount The number of cycles to perform.
	 * @param bootTimeout The time to wait for the target system to boot.
	 * @param startOffTime ??
	 * @param endOffTime ??
	 * @param offTimeStep ??
	 * @param acDcDelay ??
	 * @return RSC2_SUCCESS on success, or another result code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_PwrCycleStart(
		Rsc2_Box* box, Rsc2_PwrCycleType cycleType, int cycleCount, 
		int bootTimeout, int startOffTime, int endOffTime, 
		int offTimeStep, int acDcDelay);

	/**
	 * Reports the status of the automated power cycling in progress.
	 * @see Rsc2_PwrCycleStatus
	 * 
	 * @param box The box to get the status from.
	 * @param status The variable to write the status to.
	 * @return RSC2_SUCCESS on success, or another result code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_PwrCycleGetStatus(Rsc2_Box* box, Rsc2_PwrCycleStatus* status);

	/**
	 * Stops (pauses) the power cycling.
	 *
	 * @param box The box to stop/pause.
	 * @return RSC2_SUCCESS on success, or another result code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_PwrCycleStop(Rsc2_Box* box);

	/**
	 * Continues power cycling that had been previously stopped/paused.
	 *
	 * @param box The box to continue the power cycling.
	 * @return RSC2_SUCCESS on success, or another result code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_PwrCycleContinue(Rsc2_Box* box);

	/**
	 * Reports the total time of the power cycling.
	 * 
	 * @param box The box to get the time from.
	 * @param time The variable to write the total time value in (?? units) to.
	 * @return RSC2_SUCCESS on success, or another result code on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_PwrCycleGetTotalTime(Rsc2_Box* box, int* time);

	/** @} end PwrCycGroup */

	/**
	 * @defgroup SignalGroup Signal (button, jumper, pin, etc.) Functions 
	 * @{
	 */

	/**
	 * Sets the state for the given signal.
	 * 
	 * @param sig The signal to set the state of.
	 * @param state the state (#Rsc2_SignalState) to set the signal to.
	 * @return RSC2_SUCCESS on success, or another #Rsc2_Result value on 
	 *         failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_SetSigAssertionState(Rsc2_Signal* sig, Rsc2_SignalState state);

	/**
	 * Gets the state for the given signal.
	 *
	 * @param sig The signal to get the state (#Rsc2_SignalState) of.
	 * @return The state (#Rsc2_SignalState) of the signal.
	 */
	RSC2CAPI Rsc2_SignalState RSC2CALL Rsc2_GetSigAssertionState(Rsc2_Signal* sig);

	/**
	 * Sets the assertion type (#Rsc2_AssertionType) for the signal.
	 * 
	 * @param sig The signal to set the assertion type of.
	 * @param type The type to set the signal to.
	 * @return RSC2_SUCCESS on success, or another code on failure (#Rsc2_Result).
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_SetSigAssertionType(Rsc2_Signal* sig, Rsc2_AssertionType type);

	/**
	 * Gets the assertion type (#Rsc2_AssertionType) for the signal.
	 * 
	 * @param sig The signal to get the type of.
	 * @return The assertion type (#Rsc2_AssertionType) of the signal.
	 */
	RSC2CAPI Rsc2_AssertionType RSC2CALL Rsc2_GetSigAssertionType(Rsc2_Signal* sig);

	/**
	 * Gets the name of the signal. This is the user defined name, as opposed
	 * to the generic name (which doesn't change).
	 *
	 * @param sig The signal to get the name of.
	 * @param buf The buffer to read the name into.
	 * @param size The size of the buffer.
	 * @return The character length of the name.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetSigName(Rsc2_Signal* sig, char* buf, int size);

	/**
	 * Sets the user-defined name of a signal.
	 * 
	 * @param sig The signal to set the name for.
	 * @param name The name to set the signal to.
	 * @return RSC2_SUCCESS on success, or another result code (#Rsc2_Result) 
	 *         on failure.
	 */
	RSC2CAPI Rsc2_Result RSC2CALL Rsc2_SetSigName(Rsc2_Signal* sig, const char* name);

	/**
	 * Get the generic name of the signal.
	 * 
	 * @param sig The signal to get the generic name of.
	 * @param buf The buffer to read the generic name into.
	 * @param size The size of the buffer.
	 * @return The character length of the generic name.
	 */
	RSC2CAPI int RSC2CALL Rsc2_GetSigGenericName(Rsc2_Signal* sig, char* buf, int size);

	/**
	 * Gets the signal type (#Rsc2_SignalType) of the signal 
	 * (jumper, LED, AC port, or button).
	 * 
	 * @param sig The signal to get the type of.
	 * @return The signal type.
	 */
	RSC2CAPI Rsc2_SignalType RSC2CALL Rsc2_GetSigType(Rsc2_Signal* sig);

	/** 
	 * Sets the signal type (#Rsc2_SignalType) of the signal.
	 *
	 * @param sig The signal to set the type of.
	 * @param type The type to set the signal to.
	 */
	RSC2CAPI void RSC2CALL Rsc2_SetSigType(Rsc2_Signal* sig, Rsc2_SignalType type);

	/** @} end SignalGroup */

	/**
	 * @defgroup ScriptUtilGroup Useful Functions for Scripting Language Integration 
	 * @{
	 */

	/**
	 * Returns an array of strings representing the signal states (#Rsc2_SignalState).
	 */
	RSC2CAPI const char** RSC2CALL Rsc2_GetSignalStateStrings();

	/**
	 * Returns an array of strings representing the signal ID's (#Rsc2_SignalID).
	 * This function returns the assigned signal ID's (for instance 
	 * RSC2_ID_FPBUT_PWR).
	 */
	RSC2CAPI const char** RSC2CALL Rsc2_GetSignalIDAssignmentStrings();

	/**
	 * Returns an array of strings representing the generic signal ID's 
	 * (#Rsc2_SignalID) (for instance RSC2_ID_OUT_1).
	 */
	RSC2CAPI const char** RSC2CALL Rsc2_GetSignalIDGenericStrings();

	/**
	 * Converts a #Rsc2_BoxStatus value to its string representation.
	 */
	RSC2CAPI const char* RSC2CALL Rsc2_BoxStatusToString(Rsc2_BoxStatus status);

	/**
	 * Converts a #Rsc2_UsbMuxState value into its string representation.
	 */
	RSC2CAPI const char* RSC2CALL Rsc2_UsbMuxStateToString(Rsc2_UsbMuxState state);

	/**
	 * Converts a #Rsc2_SignalState to its string representation based on its 
	 * #Rsc2_SignalType.
	 */
	RSC2CAPI const char* RSC2CALL Rsc2_SignalStateToString(Rsc2_SignalState state, Rsc2_SignalType type);

	/**
	 * Converts a #Rsc2_SignalID to its string representation.
	 */
	RSC2CAPI const char* RSC2CALL Rsc2_SignalIDToGenericString(Rsc2_SignalID id);

	/**
	 * Converts a #Rsc2_SignalID to its string representation.
	 */
	RSC2CAPI const char* RSC2CALL Rsc2_SignalIDToAssignedString(Rsc2_SignalID id);

	/**
	 * Converts a #Rsc2_Result to its string representation.
	 */
	RSC2CAPI const char* RSC2CALL Rsc2_ResultCodeToString(Rsc2_Result rcode);

	/**
	 * Converts the string representation of #Rsc2_BoxStatus to its numeric 
	 * value.
	 * 
	 * @param sstatus The string representation.
	 * @param status A variable that receives the value.
	 * @return 0 on success, -1 on failure (probably string not recognized).
	 */
	RSC2CAPI int RSC2CALL Rsc2_StringToBoxStatus(const char* sstatus, Rsc2_BoxStatus* status);

	/**
	 * Converts the string representation of #Rsc2_UsbMuxState to its numeric
	 * value.
	 *
	 * @param sstate The string representation.
	 * @param state The variable that receives the value.
	 * @return 0 on success, -1 on failure (probably string not recognized).
	 */
	RSC2CAPI int RSC2CALL Rsc2_StringToUsbMuxState(const char* sstate, Rsc2_UsbMuxState* state);

	/**
	 * Converts the string representation of #Rsc2_SignalState to its numeric
	 * value.
	 *
	 * @param sstate The string representation.
	 * @param state The variable to receive the value.
	 * @return 0 on success, -1 on failure (probably string not recognized).
	 */
	RSC2CAPI int RSC2CALL Rsc2_StringToSignalState(const char* sstate, Rsc2_SignalState* state);

	/**
	 * Converts the string representation of #Rsc2_SignalID to its numeric
	 * value.
	 *
	 * @param ssigID The string representation.
	 * @param sigID The variable to receive the value.
	 * @return 0 on success, -1 on failure (probably string not recognized).
	 */
	RSC2CAPI int RSC2CALL Rsc2_StringToSignalID(const char* ssigID, Rsc2_SignalID* sigID);

	/**
	 * Gets the #Rsc2_SignalID table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetSigIDTable();

	/**
	 * Gets the #Rsc2_SignalState table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetSigStateTable();

	/**
	 * Gets the #Rsc2_SignalType table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetSigTypeTable();

	/**
	 * Gets the #Rsc2_AssertionType table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetAssertionTypeTable();

	/**
	 * Gets the #Rsc2_UsbMuxState table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetUsbMuxStateTable();

	/**
	 * Gets the #Rsc2_BoxStatus table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetBoxStatusTable();

	/**
	 * Gets the #Rsc2_Result table as an array of #Rsc2_SymRec. The 
	 * array can be used to add these symbols to a scripting language's 
	 * interpreter.
	 */
	RSC2CAPI const Rsc2_SymRec* RSC2CALL Rsc2_GetResultCodeTable();

	/** @} end ScriptUtilGroup */

#ifdef __cplusplus
}
#endif

#endif /* RSC2CAPI_H */
