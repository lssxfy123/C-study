#ifndef PLOT_SET_H
#define PLOT_SET_H

class PlotSet
{
  public:
    PlotSet();
    ~PlotSet();

  public:
    void AdjustXAndYAxis();
    float SpanX() const;
    float SpanY() const;

  private:
    void AdjustAxis(float& min_vlaue, float& max_value, int& number_marker);

  public:
    float x_min_value_;
    float x_max_value_;
    float y_min_value_;
    float y_max_value_;
    int x_axis_number_marker_;  // X轴标记数
    int y_axis_number_marker_;  // Y轴标记数
};

#endif // PLOT_SET_H
