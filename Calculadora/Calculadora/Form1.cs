using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Form1 : Form
    {
        String pantalla;
        
        int i = 0;
        private float[] pila;
        private int[] signo;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "1";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "2";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "3";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "/";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "4";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "5";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "6";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "*";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "7";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "8";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "9";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button12_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "-";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button13_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "0";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            pantalla = textBox1.Text;            
            //textBox2.Text = i.ToString();
           
            if(i > 0)
            {
                //textBox2.Text = pantalla[0].ToString();
                textBox1.Text = pantalla.Remove(i-1);
                
                i--;
            }
            textBox2_TextChanged(sender, e);
        }

        private void button15_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "=";
            i++;
            textBox2_TextChanged(sender, e);
        }

        private void button16_Click(object sender, EventArgs e)
        {
            //numero1 = double.Parse(textBox1.Text);
            textBox1.Text = textBox1.Text + "+";
            i++;
            textBox2_TextChanged(sender, e);
        }
        private void button17_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            i = 0;

            textBox2_TextChanged(sender, e);

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            pantalla = textBox1.Text;
            int j, k, s;
            int t;
            String c;
            Char cad;
            float resultado;
            signo = new int[50];
            pila = new float[50];
            int nume;
            k = 1;
            s = 1;
            j = 0;
            nume = 0;
            resultado = 0;
            while (j < i)
            {
                cad = pantalla[j];
                if (cad == '/' || cad == '*' || cad == '-' || cad == '+' || cad == '=')
                {
                    if(j != 0)
                    {
                        pila[k] = nume;
                        k++;
                        nume = 0;
                    }
                    if (cad == '/')
                    {
                        signo[s] = 4;
                        s++;
                    }
                    if (cad == '*')
                    {
                        signo[s] = 3;
                        s++;
                    }
                    if (cad == '-' && j != 0)
                    {
                        signo[s] = 2;
                        s++;
                    }
                    if (cad == '+')
                    {
                        signo[s] = 1;
                        s++;
                    }

                }
                else
                {
                    c = cad.ToString();
                    nume = nume * 10 + int.Parse(c);

                }
                j = j + 1;
            }
            if (i > 0)
            {
                cad = pantalla[0];
                if (cad == '-')
                {
                    pila[1] = pila[1] * (-1);
                }
            }
            j = 1;
            while (j < s)
            {
                if (signo[j] == 4 && j < k-1)
                {
                    pila[j] = pila[j] / pila[j+1];
                    t = j+1;
                    while (t < k-1)
                    {
                        pila[t] = pila[t + 1];
                        t++;

                    }
                    k = k - 1;
                    t = j;
                    while (t < s-1)
                    {
                        signo[t] = signo[t + 1];
                        t++;

                    }
                    s = s - 1;
                    j--;
 
                }
                if (signo[j] == 3 && j < k - 1)
                {
                    pila[j] = pila[j] * pila[j + 1];
                    t = j + 1;
                    while (t < k - 1)
                    {
                        pila[t] = pila[t + 1];
                        t++;

                    }
                    k = k - 1;
                    t = j;
                    while (t < s - 1)
                    {
                        signo[t] = signo[t + 1];
                        t++;

                    }
                    s = s - 1;
                    j--;

                }
                j++;
            }
            j = 1;
            if (pila[j] != 0)
            {
                resultado = resultado + pila[j];
                j++;
            }
            while (j < k)
            {
                if(signo[j-1] == 2)
                {
                    resultado =resultado - pila[j]; 
                }
                if (signo[j-1] == 1)
                {
                    resultado = resultado + pila[j];
                }
                j++;
            }
            textBox2.Text = resultado.ToString();
        }

        
       
    }
}
