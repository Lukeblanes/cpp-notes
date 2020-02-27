// https://stackoverflow.com/questions/1349542/john-carmacks-unusual-fast-inverse-square-root-quake-iii
// https://www.beyond3d.com/content/articles/8/

float d_sqrt(float number)
{
    int i;
    float x, y;
    x = number * 0.5;
    y = number;
    i = * (int *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    y = y * (1.5 - (x * y * y));
    y = y * (1.5 - (x * y * y));
    return number * y;
}

int main()
{
    // TODO: Benchmark and compare with standard math library

}