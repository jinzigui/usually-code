��10��  ͼ�εĻ��� MFC������ѧϰ�ʼǡ��ο����ϣ�����VC++��ѧ��Ƶ��by �Լ��ʼ�
 
ͼ�εĻ��ƣ����ʹ���Զ��廭�ʣ���ɫ���߿����Σ������Ϊ���������ѡ��˵���ѡ�����öԻ������ʹ�ñ�׼��ɫ�Ի������ʹ������Ի�����ѡ��Ի�����ʵ��Ԥ�����ܡ�ʵ��ѡ��Ի���ʹ������е����ݽ�������θı�Ի���Ϳؼ��ı���ɫ����θı�ؼ����ı���ɫ���԰�ť�ؼ������⴦������ڴ�������ʾһ��λͼ��
��ͼ
 
������VC6ֱ��ʵ��һ��MFC��̣�
1����������MFC AppWizard(exe)���ͣ�
2��ѡ��Single Document���ĵ�Ӧ�ó���
3��  ���
 
 
1.��Ӳ˵��� �� �� ���κ���Բ �����������Ӧ
����Դ��ͼ�еĲ˵�����ӡ��ֱ��в�ͬ��IDM����
 
IDM_DOT, IDM_LINE, IDM_RECTANGLE, IDM_ELLIPSE
 
��������view�������Ĭ�ϳ�CMainFrame����м��мǰ�����Ϊ�Ҿͷ���������󡣡ѩn��b����������
 
 
 
 
2�� ��������Ӧ�б�����ѡ�� ˽�е� UINT m_nDrawType  ���ҳ�ʼ����
��view��Ĺ��캯���У���ʼ��Ϊ0.�ٷֱ��ڵ㣬ֱ�ߣ����Σ���Բ�� function�г�ʼ��Ϊ1,2,3,4,
 
 
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
3�� Buttondown �� buttonup ��Ϣ������
 
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
 
4�� ��CPoint M_ptOrigin ����ԭ��
 
Ϊview������һ����Ա����CPoint m_ptOrigin;
����view�๹�캯���г�ʼ��Ϊ0��
 
CLesson10View::CLesson10View()
{
         // TODO: add construction code here
m_nDrawType=0;
m_ptOrigin=0;
}
 
5�� ��ͼ
 
void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
         // TODO: Add your message handler code here and/or call default
          CClientDC dc(this);
      switch (m_nDrawType)
      {
      case 1:
             dc.SetPixel(point,RGB(255,0,0));
�������һ��㲻�ɹ�����SASA�������ʡ��������������⡣����������
 
����ó������ǣ������ǶԵģ��������к�ĵ��Լ����������Ǹ����С��С���������ѩn��b
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
 
���ı仭�ʻ�ˢ�ȱʵĸı䣺
         //�����豸��
      CClientDC dc(this);
 
      //���û��ʣ���ɫ������ѡ���豸���棻
      CPen pen(PS_SOLID,1,RGB(255,0,0));
      dc.SelectObject(&pen);
 
      //���û�ˢ����ɫ͸��������ѡ���豸���棻
      CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
      dc.SelectObject(pBrush);
 
 
���������������£�
void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
         // TODO: Add your message handler code here and/or call default
         //�����豸��
CClientDC dc(this);
 
    //���û��ʣ���ɫ������ѡ���豸���棻
      CPen pen(PS_SOLID,1,RGB(255,0,0));
      dc.SelectObject(&pen);
 
      //���û�ˢ����ɫ͸��������ѡ���豸���棻
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
 
 
 
�������������������µ��뷨���ܲ������û�ͨ���Ի����Լ����������壬���ͣ���ɫ�ȣ�
 
1�����ӶԻ���IDD_DLG_SETTING, ����Setting��
 
2���ڶԻ������ֶ�����һ��
���ӡ��߿���ǩ���ͱ༭��IDC_LINE_WIDTH;
 
3�������Ӳ˵�����á���IDM_SETTING;
������Ի��������һ��class������ΪCSettingDlg��
������Ի�������Ǹ��༭�������һ��������
ͬʱ����view���Ա����m_nLineWidth;  ��UINT���͡�
��ʼ��Ϊ0
 
 
 
4�����ӡ����á��˵���Ӧ������������setting�Ի���
 
�Ȱ���clude "SettingDlg.h"
 
void CGraphicView::OnSetting()
{
      // TODO: Add your command handler code here
      CSettingDlg dlg;
      if (IDOK==dlg.DoModal())   �Ի�����ʾ����
      {
             m_nLineWidth=dlg.m_nLineWidth;
      }
}
 
 
����Ҫע����ǣ�ǰ��д�õĴ�������е��Ǹ��������õ���1.����Ҫ�ĳ����nLineWidth��������Ȼ�Ͳ���ı�ġ�������������Ĵ���д���ж�������Ҿͷ���������󡣡���
 
 
�����޸����£�
PS_SOLID,m_nLineWidth,RGB(255,0,0));
      dc.SelectObject(&pen);
 
 
�ɹ��ˡ�����^_^
 
 
5.�����öԻ�����߿�ֵ��
 
��ǰ��Ĳ����£���Ȼ������ĸĴ�С�ˣ����ǰɣ����Ǹ������£���ʾ�Ļ���0.
So��������������
 
 
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
 29����
 
 
6 ��setting�Ի���������������3����ѡ��ť��������ơ����͡���3����ѡ��ť���Ʒֱ�Ϊʵ�ߡ����ߡ����ߣ���Ϊһ�飬�ڵ�1��radio1��ѡ��group�Ϳ����ˡ����Ҷ�radio1���ã��������򵼣���Ա����int���͵�m_nLineStyle����ʼ����
 
ͬʱ��view�������һ��˽�еĳ�Ա����m_nLineStyle������ʼ��Ϊ0��Ȼ����
void CMyView::OnSetting() 
{

 CSettingDlg dlg;
	dlg.m_nLineWidth =m_nLineWidth;
	dlg.m_nLineStyle =m_nLineStyle;
      if (IDOK==dlg.DoModal())   //�Ի�����ʾ����
      {
             m_nLineWidth=dlg.m_nLineWidth;
			 m_nLineStyle=dlg.m_nLineStyle;
      }
}
ͬʱ��
 void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
 
    //���û��ʣ���ɫ������ѡ���豸���棻
      CPen pen(m_nLineStyle, m_nLineWidth,RGB(255,0,0));  //��                                      //PS_SOLID��Ϊm_nLineStyle������
      dc.SelectObject(&pen);
 }
 
 
37����
 
8. ��ɫ�Ի���CColorDialog��������CDialog
 
 
CColorDialog(
   COLORREF clrInit = 0,
//ȱʡΪ��ɫ
   DWORD dwFlags = 0,
//������ɫ�Ի���Ĺ��ܺ����
//�ο�CHOOSECOLOR structure
   CWnd* pParentWnd = NULL
//ָ���������ߴ��ڻ��丸����
);
 
 
����
     
��һ���������Ӳ˵����ɫ����IDM_COLOR;
 
�ڶ��������ӡ���ɫ���˵���Ӧ��������������ɫ�Ի���
 
void CLesson10View::OnColor()
{
         // TODO: Add your command handler code here
 CColorDialog dlg;
     dlg.DoModal();
        
}
 
������������û�ѡ����ɫ��
��view����������һ����Ա����COLORREF m_clr;
��ʼ����
CLesson10View::CLesson10View()
{
         // TODO: add construction code here
m_nDrawType=0;
m_ptOrigin=0;
m_nLineWidth=0;
    m_nLineStyle=0;
           m_clr=RGB(255, 0, 0);
 
}
���Ĳ����޸ġ���ɫ���Ӳ˵���������Ӧ������
void CLesson10View::OnColor()
{
           // TODO: Add your command handler code here
 //CColorDialog dlg;
      // dlg.DoModal();
 
           CColorDialog dlg;
 
   //CColorDialog::m_cc���Ա��������CHOOSECOLOR�ṹ������
    //CHOOSECOLOR����rgbResult�����ͱ������û�����ɫѡ��
 
      dlg.m_cc.Flags|=CC_RGBINIT;
 
  //ʹ�á�|=��������Flags��ǰ������
       // CC_RGBINIT�������Ժ���ܶ����ʼ��ɫѡ���������
 
      dlg.m_cc.rgbResult=m_clr;
      if (IDOK==dlg.DoModal())
      {
             m_clr=dlg.m_cc.rgbResult;
      }
}
 
���岽���޸Ļ���
     CPen pen(PS_DASH,m_nLineWidth,m_clr);
 
�ɹ��ˡ�������������^_^
 
��dlg.m_cc.Flags|=CC_RGBINIT;             �����ʼ����
 
50����
       
9. ����Ի���
 
��һ���������Ӳ˵�����塱��IDM_FONT;
 
�ڶ��������ӡ����塱�˵���Ӧ����������������Ի���
void CGraphicView::OnFont()
{
     // TODO: Add your command handler code here
     CFontDialog dlg;
     dlg.DoModal();
}
so���ܵ���windowsϵͳ�Լ�������Ի���
 
������������û���ѡ��Ĳ�����
����view��ĳ�Ա����CString m_strFontName;��������� CFont m_font;
��ʼ����
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
 
���Ĳ����޸ġ����塱�Ӳ˵�����Ӧ����
void CLesson10View::OnFont()
{
         // TODO: Add your command handler code here
        
          CFontDialog dlg;
    // dlg.DoModal();
          if(IDOK==dlg.DoModal())
     {
           m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
             m_strFontName=dlg.m_cf.lpLogFont->lfFaceName;
             Invalidate();   ʹ������Ч����Ϊ���ػ档
   
     }
 
 
 
} 
 
��ondraw�����
void CLesson10View::OnDraw(CDC* pDC)
{
         CLesson10Doc* pDoc = GetDocument();
         ASSERT_VALID(pDoc);
         // TODO: add draw code for native data here
 
 
         pDC->SelectObject(m_font);
 
���������ѡ�����豸�������С�
}
���ĺ�Ĵ������£������������
 
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
 
 
�ٸ���һ��������Ϊ�����Ǹ����һ����������ѡ��������ͻ����������DeleteObject����������
 
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
 
65����
 
10. ���öԻ����ʾ������
�ı��߿�������ʱ�ܹ��ڶԻ�������ʾ�����ı仯
 
��һ��������һ�����
�ڶ������ı���ID��ΪIDC_SAMPLE
�������������û��Ա༭����SettingDlg����Ϊ������ѡ��ť�������򵼣���ѡ��ť�ĸı�
���Ĳ�����
 
 
void CSettingDlg::OnChangeEdit1()
{
         // TODO: If this is a RICHEDIT control, the control will not
         // send this notification unless you override the CDialog::OnInitDialog()
         // function and call CRichEditCtrl().SetEventMask()
         // with the ENM_CHANGE flag ORed into the mask.
        
         // TODO: Add your control notification handler code here
         Invalidate();    // ��������ػ�
}
 
void CSettingDlg::OnRadio1()
{
         // TODO: Add your control notification handler code here
         Invalidate();    // ��������ػ�
 
}
 
void CSettingDlg::OnRadio2()
{
         // TODO: Add your control notification handler code here
         Invalidate();         // ��������ػ�
 
}
 
void CSettingDlg::OnRadio3()
{
         // TODO: Add your control notification handler code here
         Invalidate();       // ��������ػ�
 
}
69����
 
���Ĳ�����CSettingDlg��������Ϣ��������W_PAINT��Ϣ��
void CSettingDlg::OnPaint()
{
         CPaintDC dc(this); // device context for painting
        
         // TODO: Add your message handler code here
        
         // Do not call CDialog::OnPaint() for painting messages
}
 
���岽����дW_PAINT�ĺ���
 
void CSettingDlg::OnPaint()
{
         CPaintDC dc(this); // device context for painting
        
         // TODO: Add your message handler code here
         UpdateData();//һ��Ҫд����Ȼ�����ѡ�����ǲ���Ķ��ģ���Ҫ���������
         CPen pen(m_nLineStyle,m_nLineWidth,RGB(255,0,0));
         dc.SelectObject(&pen);
 
         CRect rect;
//      GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);  �������ǻ�ȡ����Ļ�����
    GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
         ScreenToClient(&rect);
 
 
         dc.MoveTo(rect.left+20,rect.top+rect.Height()/2);
         dc.LineTo(rect.right-20,rect.top+rect.Height()/2);
         // Do not call CDialog::OnPaint() for painting messages
}
 
��������ϣ����ȡ���������͡�
79��
��SettingDlg������һ����Ա������COLORREF  m_clr
���ҳ�ʼ��Ϊm_clr=RGB(255,0,0);



���߲����ı�Ի���ı���ɫ
�� CSettingDlg���������һ������
HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return m_brush;;
}
������ֵ��Ϊ m_brush
���˽�б���	CBrush m_brush;

���⺯���н� m_brush��ʼ��

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{m_brush.CreateSolidBrush(RGB(255,0,0));
}