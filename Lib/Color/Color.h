#pragma once
#include <iostream>
#include <string>
#define BlackBG  40   // ������� ������
#define BlackFG  30   // ��������� ������
#define RedBG  41     // ������� �������
#define RedFG  31     // ��������� �������
#define GreenBG  42   // ������� �������
#define GreenFG  32   // ��������� �������
#define YellowBG  43  // ������� ������
#define YellowFG  33  // ��������� ������
#define BlueBG  44    // ������� �����
#define BlueFG  34    // ��������� �����
#define MagentaBG  45 // ������� ���������
#define MagentaFG  35 // ��������� ���������
#define CyanBG  46    // ������� ��������
#define CyanFG  36    // ��������� ��������
#define WhiteBG  47   // ������� �����
#define WhiteFG  37   // ��������� �����

class Color
{
private:
	int BG; //���� ����
	int FG; //���� ������
public:
	Color(): BG(BlackBG), FG(WhiteFG){}
	Color(int c1, int c2) : BG(BlackBG), FG(WhiteFG) { setColor(c1,c2); }
	Color(int c1) : BG(BlackBG), FG(WhiteFG) { setColor(c1); }
	~Color() { reset(); }
	/**
	 * @brief  ����������� ���� ������� ��������
	 * @param c - ����� �����
	 * @param c2 - ����� �����2
	 * @return ������ �� ������� ���� ��� ������� �������
	 */
	Color& setColor(int �1, int �2);
	/**
	 * @brief  ����������� ���� ������� ��������
	 * @param c - ����� ����� 
	 * @return ������ �� ������� ���� ��� ������� �������
	 */
	Color& setColor(int c);
	/**
	 * @brief  ����������� ���� ������� ��������
	 * @param c - �������� ����� ������� ��������
	 * @return ������ �� ������� ���� ��� ������� �������
	 */
	Color& setColor(const Color& c);
	/**
	 * @brief ������ �������� �����
	 * @return ���������� ����� ����� ����
	 * @return ������ �� ������� ���� ��� ������� �������
	 */
	inline int getBG() { return BG; }
	/**
	 * @brief ������ ���������� �����
	 * @return ���������� ����� ����� ������
	 */
	inline int getFG() { return FG; }
	/**
	 * @brief �������� ���������� �����
	 */
	inline void operator= (Color c) { setColor(c); }
	/**
	 * @brief ������������ ������� � ����������� � ������ �����
	 * @return ������ �� ������� ���� ��� ������� �������
	 */
	Color& colorize();
	/**
	* @brief ������������� ���� ������ ��� ����
	* @param � - ����� �����
	* @param �1 - ����� ����� 2
	* @return ������ �� ������� ���� ��� ������� �������
	*/
	inline static void colorize(int c, int c1) { std::cout << "\x1b[" << c << ';' << c1 << 'm'; }
	/**
	* @brief ������������� ���� ������ ��� ����
	* @param � - ����� ����� 
	*/
	inline static void colorize(int c) { std::cout << "\x1b[" << c << 'm'; }
	/**
	* @brief ������������� ���� ������ � RGB �������
	* @param r - ������� ��������
	* @param g - ������� ��������
	* @param b - ������� ������
	*/
	inline static void colorizeRGB_FG(int r, int g, int b) { std::cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m"; }
	/**
	* @brief ������������� ���� ���� � RGB �������
	* @param r - ������� ��������
	* @param g - ������� ��������
	* @param b - ������� ������
	*/
	inline static void colorizeRGB_BG(int r, int g, int b) { std::cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m"; }
	/**
	 * @brief ���������� ���� �������, �� ������� ��� ���� �������� ����������
	 * @return ������ �� ������� ���� ��� ������� �������
	 */
	Color& reset();
	/**
	 * @brief ���������� ���� � ������� string
	 */
	inline std::string string() { return "\x1b[" + std::to_string(BG) + ';' +std::to_string(FG) + "m";}
	/**
	 * @brief ���������� ���� 0 � ������� string
	 */
	inline std::string string0() { return "\x1b[0m"; }
};

