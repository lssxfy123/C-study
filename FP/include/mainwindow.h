#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include<QTimer>

#include "../include/CyAPI.h"
#include "../include/global.h"
#include "../include/mmtimer.h"

class ChannelDialog;
class ChannelTabWidget;
class FFTDialog;
class QCheckBox;
class QMdiArea;

namespace Ui {
class main_window;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public:
    void CalculateCavity(int* pixel_array);
    void CalculatePower(int* pixel_array);
    bool SetSkin();

  protected:
    void resizeEvent(QResizeEvent *event);

  private slots:
    void OnActionChannel1(bool is_checked);
    void OnActionChannel2(bool is_checked);
    void OnActionChannel3(bool is_checked);
    void OnActionChannel4(bool is_checked);
    void OnActionChannel5(bool is_checked);
    void OnActionChannel6(bool is_checked);

    void OnActionFFT(bool is_checked);

    void OnActionInstrument1(bool is_checked);
    void OnActionInstrument2(bool is_checked);
    void OnActionInstrument3(bool is_checked);
    void OnActionInstrument4(bool is_checked);
    void OnActionInstrument5(bool is_checked);

    void OnActionMovingAverage(bool is_checked);
    void OnActionSelectAll(bool is_checked);

    void OnActionTriggerChannel1(bool is_checked);
    void OnActionTriggerChannel2(bool is_checked);
    void OnActionTriggerChannel3(bool is_checked);
    void OnActionTriggerChannel4(bool is_checked);
    void OnActionTriggerChannel5(bool is_checked);
    void OnActionTriggerChannel6(bool is_checked);

    void OnCancelChannel(ChannelNumber channel_number);
    void OnContinuousCollect();
    void OnDataSave();
    void OnExit();
    void OnImageSave();
    void OnSaveDepth();
    void OnSensorDebug();
    void OnStart();
    void OnStop();

  private:
    float CalculateCavityByPixelNumber(int fitting_count, double* fitting_factor, int pixel_number);
    float CalculatePowerByPixelNumber(int fitting_count, double* fitting_factor, int pixel_number);
    void Convert16To8(unsigned char* raw_data, int* new_data);
    void FFTConvert(float* raw_data, float* fft_data);
    void Init();
    bool IsChannelDemarcate(InstrumentNumber instrument_number, ChannelNumber channel_number);
    bool IsInstrumentDemarcate(InstrumentNumber instrument_number);
    bool IsUSBOpen(InstrumentNumber instrument_number);
    void MovingAverage(float* raw_data, int length, int average_count);
    void ReadDemarcateFile(InstrumentNumber instrument_number);
    bool ReadUSB();
    void SetDrawData();
    bool StartUSB(InstrumentNumber instrument_number);
    void StopUSB();

  private:
    Ui::main_window *ui_ptr_;
    QMdiArea* mdi_area_ptr_;
    CCyUSBDevice* USB_device_;
    CCyUSBEndPoint* command_end_point_;
    CCyUSBEndPoint* in_end_point_;

    QCheckBox* check_box_fft_ptr_;
    QCheckBox* check_box_moving_average_ptr_;

    float cavity_channel_1_array_[kChannelDataLength];  // 通道1腔长数组 
    float cavity_channel_2_array_[kChannelDataLength];  // 通道2腔长数组 
    float cavity_channel_3_array_[kChannelDataLength];  // 通道3腔长数组 
    float cavity_channel_4_array_[kChannelDataLength];  // 通道4腔长数组 
    float cavity_channel_5_array_[kChannelDataLength];  // 通道5腔长数组 
    float cavity_channel_6_array_[kChannelDataLength];  // 通道6腔长数组 
    QQueue<float> cavity_channel_1_save_queue_;         // 通道1保存数据队列
    QQueue<float> cavity_channel_2_save_queue_;         // 通道2保存数据队列
    QQueue<float> cavity_channel_3_save_queue_;         // 通道3保存数据队列
    QQueue<float> cavity_channel_4_save_queue_;         // 通道4保存数据队列
    QQueue<float> cavity_channel_5_save_queue_;         // 通道5保存数据队列
    QQueue<float> cavity_channel_6_save_queue_;         // 通道6保存数据队列
    unsigned char receive_data_[kCollectCharLength];    // 每次采集的原始数据
    float limit_cavity_channel_1_;                      // 通道1腔长限值 
    float limit_cavity_channel_2_;                      // 通道2腔长限值 
    float limit_cavity_channel_3_;                      // 通道3腔长限值 
    float limit_cavity_channel_4_;                      // 通道4腔长限值 
    float limit_cavity_channel_5_;                      // 通道5腔长限值 
    float limit_cavity_channel_6_;                      // 通道6腔长限值 
    bool is_trigger_limit_channel_1_;                   // 是否触发通道1限值
    bool is_trigger_limit_channel_2_;                   // 是否触发通道2限值
    bool is_trigger_limit_channel_3_;                   // 是否触发通道3限值
    bool is_trigger_limit_channel_4_;                   // 是否触发通道4限值
    bool is_trigger_limit_channel_5_;                   // 是否触发通道5限值
    bool is_trigger_limit_channel_6_;                   // 是否触发通道6限值
    TriggerMode trigger_mode_channel_1_;                // 通道1触发模式
    TriggerMode trigger_mode_channel_2_;                // 通道2触发模式
    TriggerMode trigger_mode_channel_3_;                // 通道3触发模式3
    TriggerMode trigger_mode_channel_4_;                // 通道4触发模式
    TriggerMode trigger_mode_channel_5_;                // 通道5触发模式
    TriggerMode trigger_mode_channel_6_;                // 通道6触发模式
    // QString data_time_array_[kChannelDataLength];

    float new_cavity_length;
    // QTimer* continuous_collect_timer_ptr_;
    MMTimer* continuous_collect_timer_ptr_;

    double fitting_factor_channel_1_array_[10];  // 通道1拟合系数
    double fitting_factor_channel_2_array_[10];  // 通道2拟合系数
    double fitting_factor_channel_3_array_[10];  // 通道3拟合系数
    double fitting_factor_channel_4_array_[10];  // 通道4拟合系数
    double fitting_factor_channel_5_array_[10];  // 通道5拟合系数
    double fitting_factor_channel_6_array_[10];  // 通道6拟合系数

    int fitting_count_1_;                        // 通道1拟合次数
    int fitting_count_2_;                        // 通道2拟合次数
    int fitting_count_3_;                        // 通道3拟合次数
    int fitting_count_4_;                        // 通道4拟合次数
    int fitting_count_5_;                        // 通道5拟合次数
    int fitting_count_6_;                        // 通道6拟合次数

    bool is_instrument_1_demarcate_;

    int send_count_;
    int save_depth_;  // 存储深度，即每次保存多少秒
    int moving_average_count_;  // 滑动平均次数
};

#endif  // MAINWINDOW_H
