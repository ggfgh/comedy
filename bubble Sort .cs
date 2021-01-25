using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _冒泡排序_
{
    class Program
    {
        static void Main(string[] args)
        {
           /* 第一次交换：8 7 6 5 4 3 2 1 0 9   9交换了9次 9 = nums.Length - 1 -i
             第二次交换：7 6 5 4 3 2 2 0 8 9   8交换了8次 8 = nums.Length - 1 - i  */
            int[] nums = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
            for (int i = 0; i < nums.Length - 1; i++)
            {
                for (int j = 0; j < nums.Length - 1 - i; j++)
                {
                    if(nums[j] > nums[j + 1])
                    {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                    }
                }
            }
            for (int k= 0; k < nums.Length; k++)
            {
                Console.Write(nums[k]);
            }
            Console.ReadKey();
        }
    }
}
