第10课  图形的绘制 MFC程序框架学习笔记【参考资料：孙鑫VC++教学视频】by 自己笔记
 
图形的绘制，如何使用自定义画笔（颜色，线宽，线形）。如何为程序中添加选项菜单和选项设置对话框，如何使用标准颜色对话框，如何使用字体对话框，在选项对话框中实现预览功能。实现选项对话框和窗口类中的数据交换。如何改变对话框和控件的背景色，如何改变控件的文本颜色，对按钮控件的特殊处理。如何在窗口中显示一幅位图。
绘图
 
现在用VC6直接实践一下MFC编程：
1、程序类型MFC AppWizard(exe)类型；
2、选择Single Document单文档应用程序
3、  完成
 
 
1.添加菜单项 点 线 矩形和椭圆 并添加命令响应
在资源视图中的菜单中添加。分别有不同的IDM——
 
IDM_DOT, IDM_LINE, IDM_RECTANGLE, IDM_ELLIPSE
 
而且是在view类里，不能默认成CMainFrame类里。切记切记啊。因为我就犯了这个错误。⊙﹏⊙b汗啊。。。
 
 
 
 
2． 在命令相应中保存其选择 私有的 UINT m_nDrawType  并且初始化。
在view类的构造函数中，初始化为0.再分别在点，直线，矩形，椭圆的 function中初始化为1,2,3,4,
 
 
void CLesson10View::OnDot()
{
         // TODO: Add your command handler code here
         m_nDrawType=1;
         }
void CLesson10View::OnLine()
{
         // TODO: Add your command handler code here
         m_nDrawType=2;
        
}
void CLesson10View::OnRectangle()
{
         // TODO: Add your command handler code here
         m_nDrawType=3;
         }
void CLesson10View::OnEllipse()
{
         // TODO: Add your command handler code here
         m_nDrawType=4;
}
3． Buttondown 和 buttonup 消息处理函数
 
void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
         // TODO: Add your message handler code here and/or call default
                   CView::OnLButtonUp(nFlags, point);
}
 
void CLesson10View::OnLButtonDown(UINT nFlags, CPoint point)
{
         // TODO: Add your message handler code here and/or call default
                   CView::OnLButtonDown(nFlags, point);
}
 
4． 用CPoint M_ptOrigin 保存原点
 
为view类增加一个成员变量CPoint m_ptOrigin;
并在view类构造函数中初始化为0；
 
CLesson10View::CLesson10View()
{
         // TODO: add construction code here
m_nDrawType=0;
m_ptOrigin=0;
}
 
5． 作图
 
void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
         // TODO: Add your message handler code here and/or call default
          CClientDC dc(this);
      switch (m_nDrawType)
      {
      case 1:
             dc.SetPixel(point,RGB(255,0,0));
在这里我画点不成功。等SASA回来，问。。。。遗留问题。。。。。。
 
结果得出结论是，程序是对的，而是运行后的点自己看不出，那个点很小很小。。。。⊙﹏⊙b
             break;
      case 2:
             dc.MoveTo(m_ptOrigin);
             dc.LineTo(point);
             break;
      case 3:
                      dc.Rectangle(CRect(m_ptOrigin, point));
                        break;
      case 4:
             dc.Ellipse(CRect(m_ptOrigin,point));
             break;
      }
         CView::OnLButtonUp(nFlags, point);
}
 
来改变画笔画刷等笔的改变：
         //定义设备表；
      CClientDC dc(this);
 
      //设置画笔，颜色，并且选择到设备里面；
      CPen pen(PS_SOLID,1,RGB(255,0,0));
      dc.SelectObject(&pen);
 
      //设置画刷，颜色透明，并且选择到设备里面；
      CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
      dc.SelectObject(pBrush);
 
 
整体完整代码如下：
void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
         // TODO: Add your message handler code here and/or call default
         //定义设备表；
CClientDC dc(this);
 
    //设置画笔，颜色，并且选择到设备里面；
      CPen pen(PS_SOLID,1,RGB(255,0,0));
      dc.SelectObject(&pen);
 
      //设置画刷，颜色透明，并且选择到设备里面；
      CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
      dc.SelectObject(pBrush);
 
      switch(m_nDrawType)
      {
      case 1:
             dc.SetPixel(point,RGB(250,60,0));
                             //dc.SetPixel(point,m_clr);
                              // dc.MoveTo(m_ptOrigin);
            // dc.LineTo(point);
             break;
      case 2:
             dc.MoveTo(m_ptOrigin);
             dc.LineTo(point);
             break;
      case 3:
                      dc.Rectangle(CRect(m_ptOrigin, point));
           break;
      case 4:
             dc.Ellipse(CRect(m_ptOrigin,point));
             break;
      }
 
                   CView::OnLButtonUp(nFlags, point);
}
 
 
 
根据上面的制作，提出新的想法：能不能让用户通过对话框，自己来设置字体，线型，颜色等？
 
1：增加对话框IDD_DLG_SETTING, 名字Setting；
 
2：在对话框上手动画出一个
增加“线宽”标签，和编辑框IDC_LINE_WIDTH;
 
3：增加子菜单项“设置”，IDM_SETTING;
在这个对话框里添加一个class，命名为CSettingDlg。
在这个对话框里的那个编辑框里添加一个变量。
同时增加view类成员变量m_nLineWidth;  是UINT类型。
初始化为0
 
 
 
4：增加“设置”菜单响应函数，并调用setting对话框；
 
先包含clude "SettingDlg.h"
 
void CGraphicView::OnSetting()
{
      // TODO: Add your command handler code here
      CSettingDlg dlg;
      if (IDOK==dlg.DoModal())   对话框显示出来
      {
             m_nLineWidth=dlg.m_nLineWidth;
      }
}
 
 
但是要注意的是，前面写好的代码里的中的那个画笔设置的是1.这里要改成这个nLineWidth变量。不然就不会改变的。。不管你下面的代码写的有多巧妙。。我就犯了这个错误。。。
 
 
代码修改如下：
PS_SOLID,m_nLineWidth,RGB(255,0,0));
      dc.SelectObject(&pen);
 
 
成功了。。。^_^
 
 
5.持设置对话框的线宽值；
 
在前面的步骤下，虽然画笔真的改大小了，但是吧，在那个设置下，显示的还是0.
So。。。。。。。
 
 
void CGraphicView::OnSetting()
{
      // TODO: Add your command handler code here
      CSettingDlg dlg;
      dlg.m_nLineWidth=m_nLineWidth; 
      if (IDOK==dlg.DoModal())
      {
             m_nLineWidth=dlg.m_nLineWidth;
      }
}
 29分钟
 
 
6 在setting对话框里面增加组框和3个单选按钮，组框名称“线型”；3个单选按钮名称分别为实线、虚线、点线；设为一组，在第1个radio1里选择group就可以了。并且对radio1设置（建立类向导）成员变量int类型的m_nLineStyle；初始化；
 
同时在view类中添加一个私有的成员变量m_nLineStyle，并初始化为0；然后在
void CMyView::OnSetting() 
{

 CSettingDlg dlg;
	dlg.m_nLineWidth =m_nLineWidth;
	dlg.m_nLineStyle =m_nLineStyle;
      if (IDOK==dlg.DoModal())   //对话框显示出来
      {
             m_nLineWidth=dlg.m_nLineWidth;
			 m_nLineStyle=dlg.m_nLineStyle;
      }
}
同时将
 void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
 
    //设置画笔，颜色，并且选择到设备里面；
      CPen pen(m_nLineStyle, m_nLineWidth,RGB(255,0,0));  //将                                      //PS_SOLID改为m_nLineStyle就行了
      dc.SelectObject(&pen);
 }
 
 
37分钟
 
8. 颜色对话框（CColorDialog）派生自CDialog
 
 
CColorDialog(
   COLORREF clrInit = 0,
//缺省为黑色
   DWORD dwFlags = 0,
//定制颜色对话框的功能和外观
//参考CHOOSECOLOR structure
   CWnd* pParentWnd = NULL
//指向其所有者窗口或其父窗口
);
 
 
代码
     
第一步：增加子菜单项“颜色”，IDM_COLOR;
 
第二步：增加“颜色”菜单响应函数，并调用颜色对话框；
 
void CLesson10View::OnColor()
{
         // TODO: Add your command handler code here
 CColorDialog dlg;
     dlg.DoModal();
        
}
 
第三步：获得用户选择颜色；
在view类里面增加一个成员变量COLORREF m_clr;
初始化：
CLesson10View::CLesson10View()
{
         // TODO: add construction code here
m_nDrawType=0;
m_ptOrigin=0;
m_nLineWidth=0;
    m_nLineStyle=0;
           m_clr=RGB(255, 0, 0);
 
}
第四步：修改“颜色”子菜单项命令响应函数；
void CLesson10View::OnColor()
{
           // TODO: Add your command handler code here
 //CColorDialog dlg;
      // dlg.DoModal();
 
           CColorDialog dlg;
 
   //CColorDialog::m_cc其成员变量就是CHOOSECOLOR结构体类型
    //CHOOSECOLOR其中rgbResult变量就保存了用户的颜色选择
 
      dlg.m_cc.Flags|=CC_RGBINIT;
 
  //使用“|=”保存其Flags以前的设置
       // CC_RGBINIT被设置以后才能对其初始颜色选择进行设置
 
      dlg.m_cc.rgbResult=m_clr;
      if (IDOK==dlg.DoModal())
      {
             m_clr=dlg.m_cc.rgbResult;
      }
}
 
第五步：修改画笔
     CPen pen(PS_DASH,m_nLineWidth,m_clr);
 
成功了。。。。。。。^_^
 
★dlg.m_cc.Flags|=CC_RGBINIT;             允许初始化；
 
50分钟
       
9. 字体对话框
 
第一步：增加子菜单项“字体”，IDM_FONT;
 
第二步：增加“字体”菜单响应函数，并调用字体对话框；
void CGraphicView::OnFont()
{
     // TODO: Add your command handler code here
     CFontDialog dlg;
     dlg.DoModal();
}
so就能调用windows系统自己的字体对话框；
 
第三步：获得用户所选择的参数；
增加view类的成员变量CString m_strFontName;和这个变量 CFont m_font;
初始化：
CLesson10View::CLesson10View()
{
         // TODO: add construction code here
m_nDrawType=0;
m_ptOrigin=0;
m_nLineWidth=0;
    m_nLineStyle=0;
           m_clr=RGB(255, 0, 0);
           m_strFontName="";
 
}
 
第四步：修改“字体”子菜单项响应函数
void CLesson10View::OnFont()
{
         // TODO: Add your command handler code here
        
          CFontDialog dlg;
    // dlg.DoModal();
          if(IDOK==dlg.DoModal())
     {
           m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
             m_strFontName=dlg.m_cf.lpLogFont->lfFaceName;
             Invalidate();   使窗口无效，是为了重绘。
   
     }
 
 
 
} 
 
在ondraw函数里。
void CLesson10View::OnDraw(CDC* pDC)
{
         CLesson10Doc* pDoc = GetDocument();
         ASSERT_VALID(pDoc);
         // TODO: add draw code for native data here
 
 
         pDC->SelectObject(m_font);
 
把这个字体选中在设备描述表中。
}
更改后的代码如下：把他输出来。
 
void CLesson10View::OnDraw(CDC* pDC)
{
         CLesson10Doc* pDoc = GetDocument();
         ASSERT_VALID(pDoc);
         // TODO: add draw code for native data here
 
 
//      pDC->SelectObject(m_font);
 
 
           CFont *pOldFont=pDC->SelectObject(&m_font);
      pDC->TextOut(0,0,m_strFontName);
      pDC->SelectObject(pOldFont);
 
}
 
 
再更改一个错误，因为上面那个输出一个，后面再选择再输出就会出错，现在用DeleteObject函数来处理。
 
void CLesson10View::OnFont()
{
         // TODO: Add your command handler code here
          CFontDialog dlg;
    // dlg.DoModal();
          if(IDOK==dlg.DoModal())
     {
                    if(m_font.m_hObject)
                             m_font.DeleteObject();
           m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
             m_strFontName=dlg.m_cf.lpLogFont->lfFaceName;
             Invalidate();
     }
}
 
65分钟
 
10. 设置对话框的示例功能
改变线宽，和线形时能够在对话框中显示线条的变化
 
第一步：设置一个组框
第二步：改变其ID号为IDC_SAMPLE
第三步：捕获用户对编辑框，在SettingDlg类中为三个单选按钮建立类向导，单选按钮的改变
第四步：在
 
 
void CSettingDlg::OnChangeEdit1()
{
         // TODO: If this is a RICHEDIT control, the control will not
         // send this notification unless you override the CDialog::OnInitDialog()
         // function and call CRichEditCtrl().SetEventMask()
         // with the ENM_CHANGE flag ORed into the mask.
        
         // TODO: Add your control notification handler code here
         Invalidate();    // 点击引起重绘
}
 
void CSettingDlg::OnRadio1()
{
         // TODO: Add your control notification handler code here
         Invalidate();    // 点击引起重绘
 
}
 
void CSettingDlg::OnRadio2()
{
         // TODO: Add your control notification handler code here
         Invalidate();         // 点击引起重绘
 
}
 
void CSettingDlg::OnRadio3()
{
         // TODO: Add your control notification handler code here
         Invalidate();       // 点击引起重绘
 
}
69分钟
 
第四步：在CSettingDlg里增加消息处理函数，W_PAINT消息。
void CSettingDlg::OnPaint()
{
         CPaintDC dc(this); // device context for painting
        
         // TODO: Add your message handler code here
        
         // Do not call CDialog::OnPaint() for painting messages
}
 
第五步：编写W_PAINT的函数
 
void CSettingDlg::OnPaint()
{
         CPaintDC dc(this); // device context for painting
        
         // TODO: Add your message handler code here
         UpdateData();//一定要写，不然如果你选择，它是不会改动的，需要这个函数。
         CPen pen(m_nLineStyle,m_nLineWidth,RGB(255,0,0));
         dc.SelectObject(&pen);
 
         CRect rect;
//      GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);  在这里是获取的屏幕的起点
    GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
         ScreenToClient(&rect);
 
 
         dc.MoveTo(rect.left+20,rect.top+rect.Height()/2);
         dc.LineTo(rect.right-20,rect.top+rect.Height()/2);
         // Do not call CDialog::OnPaint() for painting messages
}
 
第六步：希望获取到字体类型。
79分
在SettingDlg里新增一个成员变量。COLORREF  m_clr
并且初始化为m_clr=RGB(255,0,0);



第七步：改变对话框的背景色
在 CSettingDlg函数中添加一个函数
HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return m_brush;;
}
将返回值改为 m_brush
添加私有变量	CBrush m_brush;

在这函数中将 m_brush初始化

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{m_brush.CreateSolidBrush(RGB(255,0,0));
}