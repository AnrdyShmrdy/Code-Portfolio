VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Fill_Templates 
   Caption         =   "Fill_Templates"
   ClientHeight    =   9495.001
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   17670
   OleObjectBlob   =   "Fill_Templates.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Fill_Templates"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Sub UpdateBookmark(BookmarkToUpdate As String, TextToUse As String)
    Dim BMRange As Range
    Set BMRange = ActiveDocument.Bookmarks(BookmarkToUpdate).Range
    BMRange.Text = TextToUse
    ActiveDocument.Bookmarks.Add BookmarkToUpdate, BMRange
End Sub

Private Sub Label1_Click()

End Sub

Private Sub Clear_Text_Button_Click()

Me.TextBox1.Value = vbNullString
Me.TextBox2.Value = vbNullString
Me.TextBox3.Value = vbNullString
Me.TextBox4.Value = vbNullString
Me.TextBox5.Value = vbNullString
Me.TextBox6.Value = vbNullString
Me.TextBox7.Value = vbNullString
Me.TextBox8.Value = vbNullString
Me.Repaint
End Sub


Private Sub OK_Button_Click()

UpdateBookmark "Phone1", TextBox1.Text
UpdateBookmark "Phone2", TextBox1.Text
UpdateBookmark "Phone3", TextBox1.Text
UpdateBookmark "Phone4", TextBox1.Text
UpdateBookmark "Phone5", TextBox1.Text
UpdateBookmark "Phone6", TextBox1.Text
UpdateBookmark "Phone7", TextBox1.Text
UpdateBookmark "Phone8", TextBox1.Text
UpdateBookmark "Phone9", TextBox1.Text
UpdateBookmark "Phone10", TextBox1.Text
UpdateBookmark "Phone11", TextBox1.Text
UpdateBookmark "Phone12", TextBox1.Text
UpdateBookmark "Parent1", TextBox2.Text
UpdateBookmark "Parent2", TextBox2.Text
UpdateBookmark "Parent3", TextBox2.Text
UpdateBookmark "Parent4", TextBox2.Text
UpdateBookmark "Parent5", TextBox2.Text
UpdateBookmark "Parent6", TextBox2.Text
UpdateBookmark "Parent7", TextBox2.Text
UpdateBookmark "Parent8", TextBox2.Text
UpdateBookmark "Parent9", TextBox2.Text
UpdateBookmark "Parent10", TextBox2.Text
UpdateBookmark "Parent11", TextBox2.Text
UpdateBookmark "Student1", TextBox3.Text
UpdateBookmark "Student2", TextBox3.Text
UpdateBookmark "Student3", TextBox3.Text
UpdateBookmark "Student4", TextBox3.Text
UpdateBookmark "Student5", TextBox3.Text
UpdateBookmark "Student6", TextBox3.Text
UpdateBookmark "Student7", TextBox3.Text
UpdateBookmark "Student8", TextBox3.Text
UpdateBookmark "Student9", TextBox3.Text
UpdateBookmark "Student10", TextBox3.Text
UpdateBookmark "Student11", TextBox3.Text
UpdateBookmark "Student12", TextBox3.Text
UpdateBookmark "Student13", TextBox3.Text
UpdateBookmark "Grade1", TextBox4.Text
UpdateBookmark "Grade2", TextBox4.Text
UpdateBookmark "Grade3", TextBox4.Text
UpdateBookmark "Grade4", TextBox4.Text
UpdateBookmark "Grade5", TextBox4.Text
UpdateBookmark "Grade6", TextBox4.Text
UpdateBookmark "Username1", TextBox5.Text
UpdateBookmark "Username2", TextBox5.Text
UpdateBookmark "Username3", TextBox5.Text
UpdateBookmark "Username4", TextBox5.Text
UpdateBookmark "Username5", TextBox5.Text
UpdateBookmark "Username6", TextBox5.Text
UpdateBookmark "Username7", TextBox5.Text
UpdateBookmark "FOCUSID1", TextBox6.Text
UpdateBookmark "FOCUSID2", TextBox6.Text
UpdateBookmark "FOCUSID3", TextBox6.Text
UpdateBookmark "FOCUSID4", TextBox6.Text
UpdateBookmark "FOCUSID5", TextBox6.Text
UpdateBookmark "FOCUSID6", TextBox6.Text
UpdateBookmark "Course1", TextBox7.Text
UpdateBookmark "Course2", TextBox7.Text
UpdateBookmark "Teacher1", TextBox8.Text
Me.Repaint
End Sub

Private Sub Phone_Click()

End Sub


Private Sub TextBox1_Change()

End Sub

Private Sub UserForm_Click()

End Sub


