using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _飞行棋_
{
    class Program
    {
        #region 游戏前全局变量的声明
        /*用静态字段模拟全局变量*/
        public static int[] Maps = new int[100];
        //表示玩家活动的范围
        public static int[] PlayerPos = new int[2];
        //用长度为2的数组表示两个玩家的位置
        public static string[] PlayerName = new string[2];
        //玩家姓名
        static bool[] Flag = new bool[2];
        //初值为false,当为false正常游戏,为true暂停一回合
        #endregion
        /// <summary>
        /// 游戏头
        /// </summary>
        public static void GameShow()
        {
            #region 游戏头
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("************************************");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("************************************");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("************ 飞行棋1.0 *************");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine("************************************");
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.WriteLine("************************************");
            Console.ForegroundColor = ConsoleColor.DarkCyan;
            Console.WriteLine("************************************");
            #endregion
        }
        /// <summary>
        /// 初始化地图
        /// </summary>
        public static void InitailMap()
        {
            #region 初始化地图
            int[] luckyturn = { 6, 23, 40, 55, 69, 83 };//幸运轮盘◎
            for (int i = 0; i < luckyturn.Length; i++)
            {
                // int index = luckyturn[i];
                Maps[luckyturn[i]] = 1;
            }
            int[] landMine = { 5, 13, 17, 38, 50, 64, 80, 94 };//地雷☆
            for (int j = 0; j < landMine.Length; j++)
            {
                // int index = landMine[j];
                Maps[landMine[j]] = 2;
            }
            int[] pause = { 9, 27, 60, 93 };//暂停▲
            {
                for (int m = 0; m < pause.Length; m++)
                {
                    //int index = pause[m];
                    Maps[pause[m]] = 3;
                }
            }
            int[] timeTunnel = { 20, 25, 45, 63, 72, 88, 90 };//时空隧道И
            {
                for (int n = 0; n < timeTunnel.Length; n++)
                {
                    int index = timeTunnel[n];
                    Maps[index] = 4;
                }
            }
            #endregion
        }
        /// <summary>
        /// 画地图
        /// </summary>
        public static void DrawMap()
        {
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Console.WriteLine("  幸运轮盘: ◎    地雷: ◎    暂停: ▲    时空隧道: 卐 ");
  
            Console.WriteLine("==========================游戏地图==========================");
            #region 第一横行
            for (int i = 0; i < 30; i++)
            {
                Console.Write(DrawStringMap(i));
            }
            Console.WriteLine();
            #endregion
            #region 第一竖行
            for (int i = 30; i < 35; i++)
            {
                for (int j = 0; j < 29; j++)
                {
                    Console.Write("  ");
                }
                Console.Write(DrawStringMap(i));
                Console.WriteLine();
            }
            #endregion
            #region 第二横行
            for (int i = 64; i >= 35; i--)
            {
                Console.Write(DrawStringMap(i));
            }
            #endregion
            #region 第二竖行
            Console.WriteLine();
            for (int i = 65; i <= 69; i++)
            {
                Console.WriteLine(DrawStringMap(i));
            }
            #endregion
            #region 第三横行
            for (int i = 70; i <= 99; i++)
            {
                Console.Write(DrawStringMap(i));
            }
            //画完地图最后一行之后换行
            Console.WriteLine();
            #endregion
        }
        /// <summary>
        /// 从画地图的方法中抽象出来的方法
        /// </summary>
        /// <param name="i">玩家位置</param>
        /// <returns></returns>
        public static string DrawStringMap(int i)
        {
            string str = "";
            #region 画图
            if (PlayerPos[0] == PlayerPos[1] && PlayerPos[0] == i)//确保玩家在地图内
            {
                str = "><";//玩家初始位置
            }
            else if (PlayerPos[0] == i)//玩家A
            {
                //shift + 空格可以让A占一个格
                str = "Ａ";
            }
            else if (PlayerPos[1] == i)//玩家B
            {
                str = "Ｂ";
            }
            else
            {
                switch (Maps[i])
                {
                    case 0://方块
                        Console.ForegroundColor = ConsoleColor.DarkYellow;
                        str = "□"; break;
                    case 1: //幸运轮盘
                        Console.ForegroundColor = ConsoleColor.DarkMagenta;
                        str = "◎"; break;
                    case 2://地雷
                        Console.ForegroundColor = ConsoleColor.DarkYellow;
                        str = "☆"; break;
                    case 3://暂停
                        Console.ForegroundColor = ConsoleColor.Gray;
                        str = "▲"; break;
                    case 4://时空隧道
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        str = "卐"; break;
                }
            }
            #endregion
            return str;
        }
        /// <summary>
        /// 玩游戏
        /// </summary>
        /// <param name="PlayerNumber">玩家序号</param>
        public static void PlayGame(int PlayerNumber)
        {
            Random r = new Random();
            int rnumber = r.Next(1, 7);//产生1-6的随机数
            /*正常游戏*/
            Console.WriteLine("玩家{0}按任意键进行游戏", PlayerName[PlayerNumber]);
            Console.ReadKey(true);
            Console.WriteLine("玩家{0}掷出了{1}", PlayerName[PlayerNumber], rnumber);
            Console.ReadKey(true);
            PlayerPos[PlayerNumber] += rnumber;
            Limit();
            //玩家相遇
            Console.WriteLine("玩家{0}行动完了", PlayerName[PlayerNumber]);
            Console.ReadKey(true);
            if (PlayerPos[PlayerNumber] == PlayerPos[1 - PlayerNumber])
            {
                Console.WriteLine("玩家{0}踩到了玩家{1},玩家{2}退6格", PlayerName[PlayerNumber], PlayerName[1 - PlayerNumber], PlayerName[1 - PlayerNumber]);
                PlayerPos[PlayerNumber] -= 6;
                Limit();
                Console.ReadKey(true);
            }//if
            else//踩到了关卡
            {
                /*分别判断玩家遇到了什么关卡*/
                switch (Maps[PlayerPos[PlayerNumber]])
                {
                    case 0: Console.WriteLine("玩家{0}踩到了方块,安全到达", PlayerPos[PlayerNumber]);
                        Console.ReadKey(true);
                        break;

                    case 1: Console.WriteLine("玩家{0}踩到了幸运轮盘,请选择: 1---交换位置 2---轰炸对方", PlayerPos[PlayerNumber]);
                        string input = Console.ReadLine();
                        while (true)
                        {
                            if (input == "1")
                            {
                                Console.WriteLine("玩家{0}选择和玩家交换位置", PlayerName[PlayerNumber]);
                                Console.ReadKey(true);
                                int temp = PlayerPos[PlayerNumber];
                                PlayerPos[PlayerNumber] = PlayerPos[1 - PlayerNumber];
                                PlayerPos[1 - PlayerNumber] = temp;
                                Console.WriteLine("交换完成!请按任意键继续游戏");
                                Console.ReadKey(true);
                                break;
                            }//if
                            else if (input == "2")
                            {
                                Console.WriteLine("玩家{0}选择轰炸玩家{1},玩家{2}退6格", PlayerName[PlayerNumber], PlayerName[1 - PlayerNumber], PlayerName[1 - PlayerNumber]);
                                Console.ReadKey(true);
                                PlayerPos[1 - PlayerNumber] -= 6;
                                Limit();
                                Console.WriteLine("玩家{0}退了6格", PlayerName[1 - PlayerNumber]);
                                Console.ReadKey(true);
                                break;
                            }//else if
                            else
                            {
                                Console.WriteLine("只能选择1或者2,请重新选择");
                                input = Console.ReadLine();
                            }//else
                        }//while(true)
                        break;
                    case 2: Console.WriteLine("玩家{0}遇到了地雷,被炸飞了,退了6格", PlayerName[PlayerNumber]);
                        Console.ReadKey(true);
                        PlayerPos[PlayerNumber] -= 6;
                        Limit();
                        break;

                    case 3: Console.WriteLine("玩家{0}遇到了暂停,被限制一回合", PlayerName[PlayerNumber]);
                        Console.ReadKey(true);
                        Flag[PlayerNumber] = true;

                        break;
                    case 4: Console.WriteLine("玩家{0}遇到了时空隧道,前进10格", PlayerName[PlayerNumber]);
                        Console.ReadKey(true);
                        PlayerPos[PlayerNumber] += 10;
                        Limit();
                        break;
                }//switch
            }//else
            Limit();//nice
            Console.Clear();
            DrawMap();
        }
        /// <summary>
        /// 当玩家位置改变时调用此方法
        /// </summary>
        public static void Limit()
        {
            if (PlayerPos[0] < 0)
            {
                PlayerPos[0] = 0;
            }
            if (PlayerPos[0] >= 99)
            {
                PlayerPos[0] = 99;
            }
            if (PlayerPos[1] < 0)
            {
                PlayerPos[1] = 0;
            }
            if (PlayerPos[1] >= 99)
            {
                PlayerPos[1] = 99;
            }
        }
        /// <summary>
        /// 结束时的胜利图案
        /// </summary>
        public static void Win()
        {
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("                                          ◆                      ");
            Console.WriteLine("                    ■                  ◆               ■        ■");
            Console.WriteLine("      ■■■■  ■  ■                ◆■         ■    ■        ■");
            Console.WriteLine("      ■    ■  ■  ■              ◆  ■         ■    ■        ■");
            Console.WriteLine("      ■    ■ ■■■■■■       ■■■■■■■   ■    ■        ■");
            Console.WriteLine("      ■■■■ ■   ■                ●■●       ■    ■        ■");
            Console.WriteLine("      ■    ■      ■               ● ■ ●      ■    ■        ■");
            Console.WriteLine("      ■    ■ ■■■■■■         ●  ■  ●     ■    ■        ■");
            Console.WriteLine("      ■■■■      ■             ●   ■   ■    ■    ■        ■");
            Console.WriteLine("      ■    ■      ■            ■    ■         ■    ■        ■");
            Console.WriteLine("      ■    ■      ■                  ■               ■        ■ ");
            Console.WriteLine("     ■     ■      ■                  ■           ●  ■          ");
            Console.WriteLine("    ■    ■■ ■■■■■■             ■              ●         ●");
            Console.ResetColor();

        }
        static void Main(string[] args)
        {
            GameShow();
            #region 输入玩家姓名
            Console.WriteLine("请输入玩家一的姓名");
            PlayerName[0] = Console.ReadLine();
            while (PlayerName[0] == "")
            {
                Console.WriteLine("玩家一的姓名不能为空,请重新输入");
                PlayerName[0] = Console.ReadLine();
            }
            Console.WriteLine("请输入玩家二姓名");
            PlayerName[1] = Console.ReadLine();
            while (PlayerName[1] == PlayerName[0] || PlayerName[1] == "")
            {
                if (PlayerName[1] == PlayerName[0])
                {
                    Console.WriteLine("玩家二的姓名不能和玩家一的姓名相同,请重新输入");
                    PlayerName[1] = Console.ReadLine();
                }
                else
                {
                    Console.WriteLine("玩家二的姓名不能为空,请重新输入");
                    PlayerName[1] = Console.ReadLine();
                }
            }
            #endregion
            //玩家输入姓名后清屏
            Console.Clear();//清屏
            GameShow();
            Console.WriteLine("{0}的士兵用A表示", PlayerName[0]);
            Console.WriteLine("{0}的士兵用B表示", PlayerName[1]);
            //再一次初始化地图
            InitailMap();
            DrawMap();
            Console.WriteLine();
            //当两个玩家都没有到最后一个格时,玩家不停的进行游戏
            while (PlayerPos[0] < 99 && PlayerPos[1] < 99)
            {
                /*实现一轮暂停，之后恢复玩家行动*/
                if (Flag[0] == false)
                {
                    PlayGame(0);
                }
                else
                {
                    Flag[0] = false;
                }
                if (PlayerPos[0] >= 99)//判断游戏是否结束
                {
                    Console.WriteLine("玩家{0}无耻的赢了玩家{1},游戏结束", PlayerName[0], PlayerName[1]);
                    break;
                }
               
                if (Flag[1] == false)
                {
                    PlayGame(1);
                }
                else
                {
                    Flag[1] = false;
                }
                if (PlayerPos[1] >= 99)
                {
                    Console.WriteLine("玩家{0}无耻的赢了玩家{1}，游戏结束", PlayerName[1], PlayerName[0]);
                    break;
                }
            }//while

            Win();
            Console.ReadKey();

        }
    }
}
