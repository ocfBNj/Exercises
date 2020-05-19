using System;

namespace Main
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            long n = long.Parse(input[1]);

            long len = input[0].Length;

            long i = len;
            while (i < n)
            {
                i *= 2;
            }

            while (n > len)
            {
                long mid = i / 2;

                if (n > mid + 1)
                {
                    n = n - mid - 1;
                }
                else if (n == mid + 1)
                {
                    n = mid;
                }

                i /= 2;
            }

            Console.WriteLine(input[0][(int)n - 1]);
        }
    }
}
