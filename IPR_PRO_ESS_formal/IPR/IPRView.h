
// IPRView.h : CIPRView 类的接口
//

#pragma once


class CIPRView : public CView
{
protected: // 仅从序列化创建
	CIPRView();
	DECLARE_DYNCREATE(CIPRView)

// 特性
public:
	CIPRDoc* GetDocument() const;


// 操作
public:
	void CIPRView::OnPvt();

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CIPRView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnRes();
	afx_msg void OnScal();
	afx_msg void OnPropertyfluid();
	afx_msg void OnStage();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnInputData();
	afx_msg void OnPlotFig();
	afx_msg void OnWctvsrecv();
	afx_msg void OnCumlqdvswct();
	afx_msg void OnWatindx();
	afx_msg void OnWctRecRatio();
	afx_msg void OnResidwat();
	afx_msg void OnPaint();
	int FIG_TYPE;
	afx_msg void OnWctFig();
	afx_msg void OnTshModel();
	afx_msg void OnTshModelM();
	afx_msg void OnSwptEff();
	afx_msg void OnIprOpt();
	afx_msg void OnIprInf();
};

#ifndef _DEBUG  // IPRView.cpp 中的调试版本
inline CIPRDoc* CIPRView::GetDocument() const
   { return reinterpret_cast<CIPRDoc*>(m_pDocument); }
#endif

