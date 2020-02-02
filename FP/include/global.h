#ifndef GLOBAL_H
#define GLOBAL_H

// 单通道数据长度
const int kChannelDataLength = 140;

// 每台仪器一次采集的数据长度
const int kCollectDataLength = 980;

const int kFFTDataLength = 512;
//const int DataLength_Display=1400;

const int kXAxisNumMarker = 6;
const int kYAxisNumMarker = 6;

//const int kXMinValue = 1;
//const int kXMaxValue = 250;
const int kXMinValue = 0;
const int kXMaxValue = 27;

const int kFFTMaxLength = 512;

// 采集的字符串长度
// USB读取的字节长度必须为2的n次方
const int kCollectCharLength = 4096;
// const int kEffectiveCharLength = 3500;

// 单通道每秒保存数据长度
const int kChannelSaveDataLengthPerSecond = 5000;

// 最大保存深度
const int kMaxSaveDepth = 180;  // 每次最大保存3分钟

// 串口名称
//#define COM_NAME "COM1"

// 定义采集方式
enum CollectionMode
{
    COLLECTION_SINGLE  = 0,  // 单次
    COLLECTION_SERIES  = 1   // 连续
};

// 通道号
enum ChannelNumber
{
    CHANNEL_1 = 1,  // 通道1
    CHANNEL_2 = 2,  // 通道2
    CHANNEL_3 = 3,  // 通道3
    CHANNEL_4 = 4,  // 通道4
    CHANNEL_5 = 5,  // 通道5
    CHANNEL_6 = 6   // 通道6
};

// 仪器号
enum InstrumentNumber
{
    INSTRUMENT_1 = 1,  // 仪器1
    INSTRUMENT_2 = 2,  // 仪器2
    INSTRUMENT_3 = 3,  // 仪器3
    INSTRUMENT_4 = 4,  // 仪器4
    INSTRUMENT_5 = 5   // 仪器5
};

// 触发模式
enum TriggerMode
{
    HIGH = 1,  // 高于限值触发
    LOW = 2    // 低于限值触发
};

// USB仪器识别号
#define USB_INSTRUMENT_1 0x1010
#define USB_INSTRUMENT_2 0x1011

// 采集命令
const int kCollectCommand = 0x10;
const int cmd_=0x20;

// 绘图常量
const int kHeightMargin = 100;
const int kWidgthMargin = 30;

// 定义USB命令采集地址
const unsigned char kCommandAddress = 0x02;
const unsigned char kInAddress = 0x86;

const int kFitMinSensorCount = 3;  // 传感器标定最小对数
const int kFitMaxSensorCount = 50;  // 传感器标定最大对数

const int kFitMaxCount = 7;  // 最大拟合次数

const int kFitCavityCount = 2048;  // 拟合后的腔长个数

// 定义腔长标定的参数
const int kMinPixelNumber = 0;    // 标定最小像元数
const int kMaxPixelNumber = 2047;  // 标定最大像元数

const float kFitMinCavitylength = 0;  // 标定最小腔长
const float kFitMaxCavtiyength = 2048;  // 标定最大腔长

// 标定文件路径
#define DEMARCATE_PATH "../data/标定文件/"

// 保存文件路径
#define SAVE_PATH "../data/保存数据/"

// 保存图片路径
#define SAVE_IMAGE_PATH "../images/"

//采集满标志
//int flag_full;

#endif  // GLOBAL_H
