#include <cstdio>
#include <cstdlib>

int main()
{
    // For Windows
    // 对拍时不开文件输入输出
    // 当然，这段程序也可以改写成批处理的形式
    int cnt = 1;
    while (true)
    {          
        system("1.exe < 1122.in > a.out"); // 获取程序1输出
        if (system("fc a.out 1122.out"))
        {
            // 该行语句比对输入输出
            // fc返回0时表示输出一致，否则表示有不同处
            system("pause"); // 方便查看不同处
            return 0;
            // 该输入数据已经存放在test.in文件中，可以直接利用进行调试
        }
    }
}