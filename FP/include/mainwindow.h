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

    float cavity_channel_1_array_[kChannelDataLength];  // ͨ��1ǻ������ 
    float cavity_channel_2_array_[kChannelDataLength];  // ͨ��2ǻ������ 
    float cavity_channel_3_array_[kChannelDataLength];  // ͨ��3ǻ������ 
    float cavity_channel_4_array_[kChannelDataLength];  // ͨ��4ǻ������ 
    float cavity_channel_5_array_[kChannelDataLength];  // ͨ��5ǻ������ 
    float cavity_channel_6_array_[kChannelDataLength];  // ͨ��6ǻ������ 
    QQueue<float> cavity_channel_1_save_queue_;         // ͨ��1�������ݶ���
    QQueue<float> cavity_channel_2_save_queue_;         // ͨ��2�������ݶ���
    QQueue<float> cavity_channel_3_save_queue_;         // ͨ��3�������ݶ���
    QQueue<float> cavity_channel_4_save_queue_;         // ͨ��4�������ݶ���
    QQueue<float> cavity_channel_5_save_queue_;         // ͨ��5�������ݶ���
    QQueue<float> cavity_channel_6_save_queue_;         // ͨ��6�������ݶ���
    unsigned char receive_data_[kCollectCharLength];    // ÿ�βɼ���ԭʼ����
    float limit_cavity_channel_1_;                      // ͨ��1ǻ����ֵ 
    float limit_cavity_channel_2_;                      // ͨ��2ǻ����ֵ 
    float limit_cavity_channel_3_;                      // ͨ��3ǻ����ֵ 
    float limit_cavity_channel_4_;                      // ͨ��4ǻ����ֵ 
    float limit_cavity_channel_5_;                      // ͨ��5ǻ����ֵ 
    float limit_cavity_channel_6_;                      // ͨ��6ǻ����ֵ 
    bool is_trigger_limit_channel_1_;                   // �Ƿ񴥷�ͨ��1��ֵ
    bool is_trigger_limit_channel_2_;                   // �Ƿ񴥷�ͨ��2��ֵ
    bool is_trigger_limit_channel_3_;                   // �Ƿ񴥷�ͨ��3��ֵ
    bool is_trigger_limit_channel_4_;                   // �Ƿ񴥷�ͨ��4��ֵ
    bool is_trigger_limit_channel_5_;                   // �Ƿ񴥷�ͨ��5��ֵ
    bool is_trigger_limit_channel_6_;                   // �Ƿ񴥷�ͨ��6��ֵ
    TriggerMode trigger_mode_channel_1_;                // ͨ��1����ģʽ
    TriggerMode trigger_mode_channel_2_;                // ͨ��2����ģʽ
    TriggerMode trigger_mode_channel_3_;                // ͨ��3����ģʽ3
    TriggerMode trigger_mode_channel_4_;                // ͨ��4����ģʽ
    TriggerMode trigger_mode_channel_5_;                // ͨ��5����ģʽ
    TriggerMode trigger_mode_channel_6_;                // ͨ��6����ģʽ
    // QString data_time_array_[kChannelDataLength];

    float new_cavity_length;
    // QTimer* continuous_collect_timer_ptr_;
    MMTimer* continuous_collect_timer_ptr_;

    double fitting_factor_channel_1_array_[10];  // ͨ��1���ϵ��
    double fitting_factor_channel_2_array_[10];  // ͨ��2���ϵ��
    double fitting_factor_channel_3_array_[10];  // ͨ��3���ϵ��
    double fitting_factor_channel_4_array_[10];  // ͨ��4���ϵ��
    double fitting_factor_channel_5_array_[10];  // ͨ��5���ϵ��
    double fitting_factor_channel_6_array_[10];  // ͨ��6���ϵ��

    int fitting_count_1_;                        // ͨ��1��ϴ���
    int fitting_count_2_;                        // ͨ��2��ϴ���
    int fitting_count_3_;                        // ͨ��3��ϴ���
    int fitting_count_4_;                        // ͨ��4��ϴ���
    int fitting_count_5_;                        // ͨ��5��ϴ���
    int fitting_count_6_;                        // ͨ��6��ϴ���

    bool is_instrument_1_demarcate_;

    int send_count_;
    int save_depth_;  // �洢��ȣ���ÿ�α��������
    int moving_average_count_;  // ����ƽ������
};

#endif  // MAINWINDOW_H
