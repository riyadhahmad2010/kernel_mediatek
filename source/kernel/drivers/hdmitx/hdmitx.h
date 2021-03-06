// ---------------------------------------------------------------------------

#define HDMI_CHECK_RET(expr)                                                \
    do {                                                                    \
        HDMI_STATUS ret = (expr);                                           \
        if (HDMI_STATUS_OK != ret) {                                        \
            printk("[ERROR][mtkfb] HDMI API return error code: 0x%x\n"      \
                   "  file : %s, line : %d\n"                               \
                   "  expr : %s\n", ret, __FILE__, __LINE__, #expr);        \
        }                                                                   \
    } while (0)


typedef enum
{	
   HDMI_STATUS_OK = 0,

   HDMI_STATUS_NOT_IMPLEMENTED,
   HDMI_STATUS_ALREADY_SET,
   HDMI_STATUS_ERROR,
} HDMI_STATUS;
		
typedef enum
{	
   HDMI_POWER_STATE_OFF = 0,
   HDMI_POWER_STATE_ON,
   HDMI_POWER_STATE_STANDBY,
} HDMI_POWER_STATE;

typedef struct
{	
	
} HDMI_CAPABILITY;



typedef struct
{
	bool is_audio_enabled;
	bool is_video_enabled;
} hdmi_device_status;

struct hdmi_video_buffer_info
{
    void* src_vir_addr;
    unsigned int src_size;
};

extern unsigned int mtkfb_get_fb_phys_addr(void);
extern unsigned int mtkfb_get_fb_size(void);
extern unsigned int mtkfb_get_fb_va(void);

#define HDMI_IOW(num, dtype)     _IOW('H', num, dtype)
#define HDMI_IOR(num, dtype)     _IOR('H', num, dtype)
#define HDMI_IOWR(num, dtype)    _IOWR('H', num, dtype)
#define HDMI_IO(num)             _IO('H', num)

#define MTK_HDMI_AUDIO_VIDEO_ENABLE			HDMI_IO(1)
#define MTK_HDMI_AUDIO_ENABLE							HDMI_IO(2)
#define MTK_HDMI_VIDEO_ENABLE							HDMI_IO(3)
#define MTK_HDMI_GET_CAPABILITY						HDMI_IOWR(4, HDMI_CAPABILITY)
#define MTK_HDMI_GET_DEVICE_STATUS				HDMI_IOWR(5, hdmi_device_status)
#define MTK_HDMI_VIDEO_CONFIG							HDMI_IOWR(6, int)
#define MTK_HDMI_AUDIO_CONFIG							HDMI_IOWR(7, int)
#define MTK_HDMI_FORCE_FULLSCREEN_ON		HDMI_IOWR(8, int)
#define MTK_HDMI_FORCE_FULLSCREEN_OFF	HDMI_IOWR(9, int)
#define MTK_HDMI_IPO_POWEROFF	        			HDMI_IOWR(10, int)
#define MTK_HDMI_IPO_POWERON	        				HDMI_IOWR(11, int)
#define MTK_HDMI_POWER_ENABLE           			HDMI_IOW(12, int)
#define MTK_HDMI_PORTRAIT_ENABLE        			HDMI_IOW(13, int)
#define MTK_HDMI_FORCE_OPEN							HDMI_IOWR(14, int)
#define MTK_HDMI_FORCE_CLOSE							HDMI_IOWR(15, int)
#define MTK_HDMI_IS_FORCE_AWAKE                 HDMI_IOWR(16, int)
#define MTK_HDMI_ENTER_VIDEO_MODE               HDMI_IO(17)
#define MTK_HDMI_LEAVE_VIDEO_MODE               HDMI_IO(18)
#define MTK_HDMI_REGISTER_VIDEO_BUFFER          HDMI_IOW(19, struct hdmi_video_buffer_info)
#define MTK_HDMI_POST_VIDEO_BUFFER              HDMI_IOW(20, struct hdmi_video_buffer_info)



enum HDMI_report_state
{
    NO_DEVICE =0,
    HDMI_PLUGIN = 1,
};



bool is_hdmi_enable();
void hdmi_setorientation(int orientation);
void hdmi_suspend(void);
void hdmi_resume(void);
void hdmi_power_on(void);
void hdmi_power_off(void);
void hdmi_update_buffer_switch(void);
void hdmi_update(void);
HDMI_STATUS hdmi_drv_deinit(void);
void hdmi_dpi_config_clock(void);
void hdmi_dpi_power_switch(bool enable);
int hdmi_audio_config(int samplerate);
int hdmi_video_enable(bool enable);
int hdmi_audio_enable(bool enable);
int hdmi_audio_delay_mute(int latency);
void hdmi_update_impl(void);
void hdmi_set_mode(unsigned char ucMode);
void hdmi_reg_dump(void);
void hdmi_read_reg(unsigned char u8Reg);
void hdmi_write_reg(unsigned char u8Reg, unsigned char u8Data);
