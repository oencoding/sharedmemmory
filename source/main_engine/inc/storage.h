#ifndef __STORAGE_H__
#define __STORAGE_H__

#include <stdbool.h>
//#include "avi_typedef.h"
#include "sdk_struct.h"

#define GRD_SD_MOUNT_POINT      "/mnt/sd_card"

#define  BOOL uint32_t

#define GRD_NAME_LEN    32  
#define GRD_PASSWORD    32  
#define GRD_MAX_PATH_LEN    256

#define GRD_NET_FILE_SUCCESS       1000
#define GRD_NET_FILE_NOFIND         1001
#define GRD_NET_ISFINDING             1002
#define GRD_NET_NOMOREFILE         1003
#define GRD_NET_FILE_EXCEPTION   1004

typedef int (* sna_callback)(int ch,sdk_snap_info_t *snap_info,char *path); //图片抓拍回调函数

extern sna_callback  cb;

#define RECORD_VIDEO_PATH		"video"
#define VIDEO_NODE_FILE_NAME	"avrecordindex.dat"


typedef struct tag_NodeIndex
{
    unsigned int recordtype;//0 normal ;1 event
    int64_t uiStartTime;
    unsigned int uiDurations;
}NodeIndex;

typedef struct tag_NodeIndex_EX
{
	unsigned int recordtype;//0 normal ;1 event
    unsigned int uiStartTime;
    unsigned int uiDurations;
    NodeIndex *next;
}NodeIdx_LinkList;


#define SINGNLE_NODE_SIZE  sizeof(NodeIndex)

typedef enum
{
	ENC_TYPE_H264 , //H264
	ENC_TYPE_MPEG,      //< MPEG4
	ENC_TYPE_MJPEG,    //< Motion JPEG
	ENC_TYPE_YUV422,
	ENC_TYPE_COUNT     //< do not use	
}eEncType;

typedef enum {
    GRDRET_LOCK_FAILED          = (-8),
    GRDRET_TIMEOUT              = (-7),
    GRDRET_UNKNOWN_STREAM_TYPE  = (-6),
    GRDRET_RESOURCE_EXCEED      = (-5),
    GRDRET_OUT_OF_MEMORY        = (-4),
    GRDRET_INTERNAL_ERROR       = (-3),
    GRDRET_INVALID_ARGUMENT     = (-2),
    GRDRET_FAILED               = (-1),
    GRDRET_SUCCESS              = 0,
    GRDRET_BUF_NO_DATA          = (1),
} GrdRet;

typedef enum __GRD_AV_FORMART
{
        GRD_ENC_TYPE_PCMU   = 0,
        GRD_ENC_TYPE_G721   = 2,
        GRD_ENC_TYPE_GSM    = 3,
        GRD_ENC_TYPE_G723   = 4,
        GRD_ENC_TYPE_LPC    = 7,
        GRD_ENC_TYPE_G729   = 18,
        GRD_ENC_TYPE_G711A  = 19,
        GRD_ENC_TYPE_G711U  = 20,
        GRD_ENC_TYPE_G726   = 21,
        GRD_ENC_TYPE_G729A  = 22,
        GRD_ENC_TYPE_LPCM   = 23,
        GRD_ENC_TYPE_H263   = 34,
        GRD_ENC_TYPE_AAC    = 37,
        GRD_ENC_TYPE_MP3    = 43,
        GRD_ENC_TYPE_ADPCMA = 49,
        GRD_ENC_TYPE_H264   = 96,
        GRD_ENC_TYPE_MPEG   = 230,
        GRD_ENC_TYPE_AMR    = 1001,
        GRD_ENC_TYPE_MJPEG  = 1002,
} GRD_ENCODE_TYPE_E;



typedef enum tagGRD_VIDEO_ENC_TYPE_E
{
        GRD_VIDEO_ENC_TYPE_H264 ,   // H264
        GRD_VIDEO_ENC_TYPE_MPEG,    // < MPEG4
        GRD_VIDEO_ENC_TYPE_MJPEG,   // < Motion JPEG
        GRD_VIDEO_ENC_TYPE_YUV422,
        GRD_VIDEO_ENC_TYPE_COUNT,   // < do not use
} GRD_VIDEO_ENC_TYPE_E;

typedef enum tagGRD_AUDIO_ENC_TYPE_E
{
        GRD_ADPCM_8K16B = 0x90,
        GRD_ADPCM_16K16B = 0x91,
        GRD_G711A_8K16B = 0x92,
        GRD_G7221C_32k  = 0x93,
        GRD_LPCM_8K16B = 0x94,
        GRD_LPCM_441K16B = 0x95,
        GRD_G711U_8K16B = 0x96,
        GRD_AAC_8K16B = 0x97,
        GRD_PCM_8K16B = 0x98
} GRD_AUDIO_ENC_TYPE_E;

typedef enum
{
        GRD_SD_FORMAT_STATUS_IDLE   = 0,
        GRD_SD_FORMAT_FAIL          = 1,
        GRD_SD_FROMAT_DONE          = 2,
        GRD_SD_NOT_EXIST            = 3,
} GRD_SDFORMAT_STATUS_E;

typedef enum
{
        GRD_SD_FORMAT_UNKNOWN      = -1,
        GRD_SD_FORMAT_FAT32        = 0,
        GRD_SD_FORMAT_EXFAT        = 1,
        GRD_SD_FROMAT_NTFS         = 2,
} GRD_SDFORMAT_TYPE_E;

typedef struct tagGRD_NET_SDCARD_INFO
{
        unsigned long long  ullSdCardCapacity;      // SD卡的的总容量
        unsigned long long  ullSdCardUsedCapacity;  // SD卡已经用掉的容量
        unsigned long long  ullSdFreeCapacity;      // SD卡剩余的容量
        BOOL                bFormatEnabled;
        GRD_SDFORMAT_STATUS_E enFormatStatus;
        GRD_SDFORMAT_TYPE_E bFormatType;
} GRD_SDCARD_INFO;
/*-----录像搜索用到的信息--------*/
typedef struct tagINDEX_NODE
{
    uint32_t ch_num;
    uint64_t start;
    uint64_t stop;
}INDEX_NODE;
typedef struct tagRECORDING_FILE_INFO
{
    int rec_type;
    INDEX_NODE rec_file_info;
}RECORDING_FILE_INFO;

typedef struct tagFILE_NODE
{
    char path[128];
    uint64_t start;
    uint64_t stop;
    struct tagFILE_NODE *next;
} FILE_NODE;

typedef struct tagFILE_LIST
{
    uint64_t start;
    uint64_t stop;
    uint32_t type;
    uint32_t ch_num;

    FILE_NODE *head;
    uint32_t len;
    uint32_t index;
}FILE_LIST, *LPFILE_LIST;
#if 0
// 用于系统校正时间和回放搜素
typedef struct tagGRD_TIME
{
        uint32_t    dwYear;
        uint32_t    dwMonth;
        uint32_t    dwDay;
        uint32_t    dwHour;
        uint32_t    dwMinute;
        uint32_t    dwSecond;
} GRD_TIME;
#endif

// 回放搜索文件数据结构
typedef struct tagGRD_FILE_INFO
{
        uint32_t        dwSize;
        uint32_t        dwFileType;
        uint32_t        dwFileSize;
        sdk_time_t     stStartTime;
        sdk_time_t     stStopTime;
        char         csFileName[GRD_MAX_PATH_LEN];
} GRD_REC_FILE_INFO;

// PC端回放请求数据结构
typedef struct tagGRD_PLAYBACK_REQ
{
        uint32_t  dwSize;
        char   csFileName[GRD_MAX_PATH_LEN];
} GRD_PLAYBACK_REQ;


// 实时数据/回放数据Header
typedef struct GRD_NET_FRAME_HEADER
{
        uint32_t   dwSize;
        uint32_t   dwFrameIndex; // 当前数据包的序号
        struct timeval stTimestamp;   // 当前数据包的时间戳(精确到ms)
        sdk_time_t stFrameTime; // 当前数据包的时间

        uint32_t   dwVideoSize;  // 当前视频帧的大小(**区别于安普是DWORD**)
        uint32_t    wVideoWidth;  // 当前视频的宽度
        uint32_t    wVideoHeight; // 当前视频的高度

	    uint32_t   dwAudioIndex;
        uint32_t    wAudioSize;   // 当前音频数据包的大小
        uint8_t    byFrameType;  // 当前视频帧的类型 0：I帧；1：P帧；2：B帧，只针对视频
        uint8_t    byVideoCode;  // 当前视频的编码压缩类型
        uint8_t    byAudioCode;  // 当前音频的编码压缩类型
        uint8_t    byReserved1;  // 按4位对齐
} GRD_NET_FRAME_HEADER;

typedef struct tagGRD_AviPB_Info
{
        float avi_fps;
        uint32_t video_width;
        uint32_t video_height;
        int video_count;

        GRD_VIDEO_ENC_TYPE_E video_type;
        GRD_AUDIO_ENC_TYPE_E audio_type;
} GRD_AviPB_Info;

#if 0
sdk_record_cond_t
typedef  struct tagGRD_NET_FINDDATA
{
        uint32_t        dwSize;
        sdk_time_t     stSearchStartTime;
        sdk_time_t     stSearchStopTime;
        SDK_RECORD_TYPE_E        dwFileType;
        int          nChannel;
        // GRD_REC_FILE_INFO  stFileInfo[100];
} GRD_NET_FINDDATA;

#endif

/*****************************************************************************
 函 数 名  : st_refresh_time_zone
 功能描述  : 刷新时区  应该录像库需要用到UTC 时间 和localtime
 输入参数  : int time_zone: 0 ~24   表示24个时区
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2015年10月08日
    作    者   : bingchuan
    修改内容   : 新生成函数

*****************************************************************************/


extern int st_refresh_time_zone(int time_zone);

/*****************************************************************************
 函 数 名  : st_record_init
 功能描述  : 初始化整个录像库 
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2015年6月25日
    作    者   : bingchuan
    修改内容   : 新生成函数

 注: sna_callback func  是图片抓拍回调函数，不需要时可以去掉

*****************************************************************************/
extern int st_record_init(sna_callback func);

/*****************************************************************************
 函 数 名  : st_record_deinit
 功能描述  : 停止整个录像库的功能
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2015年6月25日
    作    者   : bingchuan
    修改内容   : 新生成函数

*****************************************************************************/
extern int st_record_deinit();
/*****************************************************************************
 函 数 名  : st_record_start
 功能描述  : 开始录像
 输入参数  : SDK_RECORD_TYPE_E record_type  录像类型 参见SDK_RECORD_TYPE_E
             int duration     每段录像的时长 但是是秒
 输出参数  : 
 返 回 值  :  出错 返回-1,  正常设置返回0   如果当前正在录像就返回当前的录像类型 SDK_RECORD_TYPE_E
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年6月18日
    作    者   : bingchuan
    修改内容   : 新生成函数

*****************************************************************************/

extern int st_record_start(SDK_RECORD_TYPE_E record_type,int duration);
/*****************************************************************************
 函 数 名  : st_record_stop
 功能描述  : 停止录像
 输入参数  : SDK_RECORD_TYPE_E record_type  
 输出参数  : 无
 返 回 值  :  成功返回0  失败返回 -1
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2015年6月25日
    作    者   : bingchuan
    修改内容   : 新生成函数

*****************************************************************************/
extern int st_record_stop(SDK_RECORD_TYPE_E record_type);
/*****************************************************************************
 函 数 名  : st_get_event_status
 功能描述  : 获取事件录像状态
 输入参数  : int * status
 输出参数  : status 为0 表示没有录像
 				status 为1 表示正在录像
 
 修改历史      :
  1.日    期   : 2015年8月15日
    作    者   :  Wrong
    修改内容   : 新生成函数

*****************************************************************************/  
extern int st_get_event_status();

// 搜索
extern int st_find_file_close(int findHandle);
extern int st_find_file_open(sdk_record_cond_t *param, int *findHandle);
extern int st_find_next_file(int findHandle, GRD_REC_FILE_INFO *file_info);
//extern int st_locate_no(char *file, time_t seekTime, AviPBHandle *pPBHandle);

//回放
extern int st_playback_by_name(GRD_PLAYBACK_REQ *param, int *playHandler);
extern int st_playback_during_rec( GRD_PLAYBACK_REQ *param, int *playHandler );
extern int st_playback_get_frame(int playHandler, char *pBuff, int *pSize, GRD_NET_FRAME_HEADER *pHeader);
extern int st_playback_get_frame_AorV(int bGetVideo, int playHandler, char *pBuff, int *pSize, GRD_NET_FRAME_HEADER *pHeader);
extern int st_playback_get_info(int playHandler, GRD_AviPB_Info *pPB_Info);
extern int st_playback_seek_file( char *path,  time_t seekTime, int *playHandler );
extern int st_playback_stop(int playHandler);
extern int st_playback_delete(const char * file_name);//record delete


//
extern int st_delete_SD_record_file(char *file, int fileType);
extern GrdRet st_get_SD_card_info(GRD_SDCARD_INFO *param);
extern GrdRet st_SD_card_format(GRD_SDCARD_INFO *param);

//dropbox
int dropbox_sendFile_record_get(char *pBuf, int bufSize);
int dropbox_sendFile_record_del();

#endif
