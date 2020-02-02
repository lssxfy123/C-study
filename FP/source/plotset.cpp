#include "../include/plotset.h"

#include <cmath>
#include <QtDebug>
#include "../include/global.h"

PlotSet::PlotSet()
{
}

PlotSet::~PlotSet()
{
}

void PlotSet::AdjustXAndYAxis()
{
    AdjustAxis(x_min_value_, x_max_value_, x_axis_number_marker_);
    // AdjustAxis(y_min_value_, y_max_value_, y_axis_number_marker_);
}

float PlotSet::SpanX() const
{
    return (x_max_value_ - x_min_value_);
}

float PlotSet::SpanY() const
{
    return (y_max_value_ - y_min_value_);
}

// Ð£×¼×ø±êÖá
void PlotSet::AdjustAxis(float& min_vlaue, float& max_value, int& number_marker)
{
    //qDebug() << "before adjust" << min_vlaue;
    //qDebug() << "before adjust" << max_value;
    const int min_number_marker = 5;
    float gross_step = (max_value - min_vlaue) / min_number_marker;

    if (gross_step < 1e-4)
    {
        return;
    }

    float step = std::pow(10, std::floor(std::log10(gross_step)));

    if (5 * step < gross_step) {
        step *= 5;
    } else if (2 * step < gross_step) {
        step *= 2;
    }

    number_marker = int(std::ceil(max_value / step) - std::floor(min_vlaue / step));
    if (number_marker < min_number_marker)
        number_marker = min_number_marker;
    min_vlaue = std::floor(min_vlaue / step) * step;
    max_value = std::ceil(max_value / step) * step;

    //qDebug() << "after adjust" << min_vlaue;
    //qDebug() << "after adjust" << max_value;
}
