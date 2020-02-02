#ifndef GLOBAL_H
#define GLOBAL_H

// ��ͨ�����ݳ���
const int kChannelDataLength = 140;

// ÿ̨����һ�βɼ������ݳ���
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

// �ɼ����ַ�������
// USB��ȡ���ֽڳ��ȱ���Ϊ2��n�η�
const int kCollectCharLength = 4096;
// const int kEffectiveCharLength = 3500;

// ��ͨ��ÿ�뱣�����ݳ���
const int kChannelSaveDataLengthPerSecond = 5000;

// ��󱣴����
const int kMaxSaveDepth = 180;  // ÿ����󱣴�3����

// ��������
//#define COM_NAME "COM1"

// ����ɼ���ʽ
enum CollectionMode
{
    COLLECTION_SINGLE  = 0,  // ����
    COLLECTION_SERIES  = 1   // ����
};

// ͨ����
enum ChannelNumber
{
    CHANNEL_1 = 1,  // ͨ��1
    CHANNEL_2 = 2,  // ͨ��2
    CHANNEL_3 = 3,  // ͨ��3
    CHANNEL_4 = 4,  // ͨ��4
    CHANNEL_5 = 5,  // ͨ��5
    CHANNEL_6 = 6   // ͨ��6
};

// ������
enum InstrumentNumber
{
    INSTRUMENT_1 = 1,  // ����1
    INSTRUMENT_2 = 2,  // ����2
    INSTRUMENT_3 = 3,  // ����3
    INSTRUMENT_4 = 4,  // ����4
    INSTRUMENT_5 = 5   // ����5
};

// ����ģʽ
enum TriggerMode
{
    HIGH = 1,  // ������ֵ����
    LOW = 2    // ������ֵ����
};

// USB����ʶ���
#define USB_INSTRUMENT_1 0x1010
#define USB_INSTRUMENT_2 0x1011

// �ɼ�����
const int kCollectCommand = 0x10;
const int cmd_=0x20;

// ��ͼ����
const int kHeightMargin = 100;
const int kWidgthMargin = 30;

// ����USB����ɼ���ַ
const unsigned char kCommandAddress = 0x02;
const unsigned char kInAddress = 0x86;

const int kFitMinSensorCount = 3;  // �������궨��С����
const int kFitMaxSensorCount = 50;  // �������궨������

const int kFitMaxCount = 7;  // �����ϴ���

const int kFitCavityCount = 2048;  // ��Ϻ��ǻ������

// ����ǻ���궨�Ĳ���
const int kMinPixelNumber = 0;    // �궨��С��Ԫ��
const int kMaxPixelNumber = 2047;  // �궨�����Ԫ��

const float kFitMinCavitylength = 0;  // �궨��Сǻ��
const float kFitMaxCavtiyength = 2048;  // �궨���ǻ��

// �궨�ļ�·��
#define DEMARCATE_PATH "../data/�궨�ļ�/"

// �����ļ�·��
#define SAVE_PATH "../data/��������/"

// ����ͼƬ·��
#define SAVE_IMAGE_PATH "../images/"

//�ɼ�����־
//int flag_full;

#endif  // GLOBAL_H
