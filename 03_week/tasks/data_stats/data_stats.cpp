#include <math.h>
#include <vector>

struct DataStats {
    double avg = 0.0;
    double sd = 0.0;
};

DataStats CalculateDataStats(const std::vector<int>& data) {

    DataStats stats;

    // Возвращаем пустую структуру, если нет данных
    if (data.empty())
        return stats;

    // Для решения задачи был использован алгоритм Welford'a для одного прохода
    for (size_t i = 0; i < data.size(); i++) {
        const double& value = data[i]; // Получение текущего значения элемента из массива

        double delta = value - stats.avg;        // Разница между текущим значением и средним
        stats.avg += delta / (i + 1);            // Накопление среднего значения
        stats.sd += delta * (value - stats.avg); // Накопление суммы квадратов отклонений
    }

    // Вычисляем стандартное отклонение
    stats.sd = sqrt(stats.sd / data.size());

    return stats;
}
