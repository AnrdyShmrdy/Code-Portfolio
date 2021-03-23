VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Fill_Templates 
   Caption         =   "Fill_Templates"
   ClientHeight    =   8835.001
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   11370
   OleObjectBlob   =   "Fill_Templates.frx":0000
   ShowModal       =   0   'False
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Fill_Templates"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim isFlex As Boolean
Dim isFT As Boolean
Sub FOCUSID_Fill()
If isFT = True Then
    UpdateBookmark "FOCUSID1", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID2", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID3", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID4", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID5", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID6", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID7", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID8", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID9", FOCUSIDBox.Text
    UpdateBookmark "FOCUSID10", FOCUSIDBox.Text
End If
End Sub

Sub Course_Clear()
If isFlex = True Then
    ClearBookmark "Course1"
    ClearBookmark "Course2"
    ClearBookmark "Course3"
    ClearBookmark "Course4"
    ClearBookmark "Course5"
End If
'No FT If Statment needed, as there is no course field in the FT descriptions'
ClearBookmark "Course6"
End Sub





Sub Parent_Clear()
If isFlex = True Then
    ClearBookmark "Parent1"
    ClearBookmark "Parent2"
    ClearBookmark "Parent3"
    ClearBookmark "Parent4"
    ClearBookmark "Parent5"
    ClearBookmark "Parent6"
    ClearBookmark "Parent7"
    ClearBookmark "Parent8"
    ClearBookmark "Parent9"
    ClearBookmark "Parent10"
    ClearBookmark "Parent11"
    ClearBookmark "Parent12"
    ClearBookmark "Parent13"
    ClearBookmark "Parent14"
    ClearBookmark "Parent15"
    ClearBookmark "Parent16"
End If
If isFT = True Then
    ClearBookmark "Parent17"
    ClearBookmark "Parent18"
    ClearBookmark "Parent19"
    ClearBookmark "Parent20"
    ClearBookmark "Parent21"
    ClearBookmark "Parent22"
    ClearBookmark "Parent23"
    ClearBookmark "Parent24"
    ClearBookmark "Parent25"
    ClearBookmark "Parent26"
    ClearBookmark "Parent27"
End If
ClearBookmark "Parent28"
End Sub

Sub Phone_Clear()
If isFlex = True Then
    ClearBookmark "Phone1"
    ClearBookmark "Phone2"
    ClearBookmark "Phone3"
    ClearBookmark "Phone4"
    ClearBookmark "Phone5"
    ClearBookmark "Phone6"
    ClearBookmark "Phone7"
    ClearBookmark "Phone8"
    ClearBookmark "Phone9"
    ClearBookmark "Phone10"
    ClearBookmark "Phone11"
    ClearBookmark "Phone12"
    ClearBookmark "Phone13"
    ClearBookmark "Phone14"
    ClearBookmark "Phone15"
    ClearBookmark "Phone16"
End If
If isFT = True Then
    ClearBookmark "Phone17"
    ClearBookmark "Phone18"
    ClearBookmark "Phone19"
    ClearBookmark "Phone20"
    ClearBookmark "Phone21"
    ClearBookmark "Phone22"
    ClearBookmark "Phone23"
    ClearBookmark "Phone24"
    ClearBookmark "Phone25"
    ClearBookmark "Phone26"
    ClearBookmark "Phone27"
End If
ClearBookmark "Phone28"
End Sub

Sub Student_Clear()
If isFlex = True Then
    ClearBookmark "Student1"
    ClearBookmark "Student2"
    ClearBookmark "Student3"
    ClearBookmark "Student4"
    ClearBookmark "Student5"
    ClearBookmark "Student6"
    ClearBookmark "Student7"
    ClearBookmark "Student8"
    ClearBookmark "Student9"
    ClearBookmark "Student10"
    ClearBookmark "Student11"
    ClearBookmark "Student12"
    ClearBookmark "Student13"
    ClearBookmark "Student14"
    ClearBookmark "Student15"
    ClearBookmark "Student16"
    ClearBookmark "Student17"
    ClearBookmark "Student18"
    ClearBookmark "Student19"
    ClearBookmark "Student20"
End If
If isFT = True Then
    ClearBookmark "Student21"
    ClearBookmark "Student22"
    ClearBookmark "Student23"
    ClearBookmark "Student24"
    ClearBookmark "Student25"
    ClearBookmark "Student26"
    ClearBookmark "Student27"
    ClearBookmark "Student28"
    ClearBookmark "Student29"
    ClearBookmark "Student30"
    ClearBookmark "Student31"
End If
ClearBookmark "Student32"
ClearBookmark "Student33"
End Sub

Sub Teacher_Clear()
ClearBookmark "Teacher1"
ClearBookmark "Teacher2"
'No FT If Statment needed, as teacher does not appear in any FT descriptions'
ClearBookmark "Teacher3"
ClearBookmark "Teacher4"
End Sub

Sub Username_Clear()
If isFlex = True Then
    ClearBookmark "Username1"
    ClearBookmark "Username2"
    ClearBookmark "Username3"
    ClearBookmark "Username4"
    ClearBookmark "Username5"
    ClearBookmark "Username6"
    ClearBookmark "Username7"
    ClearBookmark "Username8"
    ClearBookmark "Username9"
    ClearBookmark "Username10"
    ClearBookmark "Username11"
    ClearBookmark "Username12"
    ClearBookmark "Username13"
    ClearBookmark "Username14"
    ClearBookmark "Username15"
    ClearBookmark "Username16"
    ClearBookmark "Username17"
End If
If isFT = True Then
    ClearBookmark "Username18"
    ClearBookmark "Username19"
End If
ClearBookmark "Username20"
ClearBookmark "Username21"
End Sub

Sub ClearBookmark(BookmarkToUpdate As String)
    Dim BMRange As Range
    Set BMRange = ActiveDocument.Bookmarks(BookmarkToUpdate).Range
    BMRange.Text = vbNullString
    ActiveDocument.Bookmarks.Add BookmarkToUpdate, BMRange
End Sub
Sub Details_Clear()
If isFlex = True Then
    ClearBookmark "Details1"
    ClearBookmark "Details2"
    ClearBookmark "Details3"
    ClearBookmark "Details4"
    ClearBookmark "Details5"
    ClearBookmark "Details6"
    ClearBookmark "Details7"
    ClearBookmark "Details8"
    ClearBookmark "Details9"
    ClearBookmark "Details10"
    ClearBookmark "Details11"
    ClearBookmark "Details12"
    ClearBookmark "Details13"
    ClearBookmark "Details14"
End If
If isFT = True Then
    ClearBookmark "Details15"
    ClearBookmark "Details16"
    ClearBookmark "Details17"
    ClearBookmark "Details18"
    ClearBookmark "Details19"
    ClearBookmark "Details20"
    ClearBookmark "Details21"
    ClearBookmark "Details22"
    ClearBookmark "Details23"
End If
ClearBookmark "Details24"
End Sub

Sub Email_Clear()
If isFlex = True Then
ClearBookmark "Email1"
ClearBookmark "Email2"
End If
If isFT = True Then
    ClearBookmark "Email3"
    ClearBookmark "Email4"
    ClearBookmark "Email5"
    ClearBookmark "Email6"
    ClearBookmark "Email7"
    ClearBookmark "Email8"
End If
ClearBookmark "Email9"
End Sub

Sub Course_Fill()
If isFlex = True Then
    UpdateBookmark "Course1", CourseBox.Text
    UpdateBookmark "Course2", CourseBox.Text
    UpdateBookmark "Course3", CourseBox.Text
    UpdateBookmark "Course4", CourseBox.Text
    UpdateBookmark "Course5", CourseBox.Text
End If
'Course does not need a FT if statment, since there are no course fields in the FT Descriptions'
UpdateBookmark "Course6", CourseBox.Text
End Sub

Sub Details_Fill()
If isFlex = True Then
    UpdateBookmark "Details1", DetailsBox.Text
    UpdateBookmark "Details2", DetailsBox.Text
    UpdateBookmark "Details3", DetailsBox.Text
    UpdateBookmark "Details4", DetailsBox.Text
    UpdateBookmark "Details5", DetailsBox.Text
    UpdateBookmark "Details6", DetailsBox.Text
    UpdateBookmark "Details7", DetailsBox.Text
    UpdateBookmark "Details8", DetailsBox.Text
    UpdateBookmark "Details9", DetailsBox.Text
    UpdateBookmark "Details10", DetailsBox.Text
    UpdateBookmark "Details11", DetailsBox.Text
    UpdateBookmark "Details12", DetailsBox.Text
    UpdateBookmark "Details13", DetailsBox.Text
    UpdateBookmark "Details14", DetailsBox.Text
End If
If isFT = True Then
    UpdateBookmark "Details15", DetailsBox.Text
    UpdateBookmark "Details16", DetailsBox.Text
    UpdateBookmark "Details17", DetailsBox.Text
    UpdateBookmark "Details18", DetailsBox.Text
    UpdateBookmark "Details19", DetailsBox.Text
    UpdateBookmark "Details20", DetailsBox.Text
    UpdateBookmark "Details21", DetailsBox.Text
    UpdateBookmark "Details22", DetailsBox.Text
    UpdateBookmark "Details23", DetailsBox.Text
End If
UpdateBookmark "Details24", DetailsBox.Text
End Sub

Sub Email_Fill()
If isFlex = True Then
    UpdateBookmark "Email1", EmailBox.Text
    UpdateBookmark "Email2", EmailBox.Text
End If
If isFT = True Then
    UpdateBookmark "Email3", EmailBox.Text
    UpdateBookmark "Email4", EmailBox.Text
    UpdateBookmark "Email5", EmailBox.Text
    UpdateBookmark "Email6", EmailBox.Text
    UpdateBookmark "Email7", EmailBox.Text
    UpdateBookmark "Email8", EmailBox.Text
End If
UpdateBookmark "Email9", EmailBox.Text
End Sub

Sub Grade_Fill()
If isFlex = True Then
    UpdateBookmark "Grade1", GradeBox.Text
    UpdateBookmark "Grade2", GradeBox.Text
    UpdateBookmark "Grade3", GradeBox.Text
    UpdateBookmark "Grade4", GradeBox.Text
    
End If
If isFT = True Then
    UpdateBookmark "Grade5", GradeBox.Text
    UpdateBookmark "Grade6", GradeBox.Text
    UpdateBookmark "Grade7", GradeBox.Text
    UpdateBookmark "Grade8", GradeBox.Text
    UpdateBookmark "Grade9", GradeBox.Text
    UpdateBookmark "Grade10", GradeBox.Text
    UpdateBookmark "Grade11", GradeBox.Text
    UpdateBookmark "Grade12", GradeBox.Text
    UpdateBookmark "Grade13", GradeBox.Text
End If
UpdateBookmark "Grade14", GradeBox.Text
End Sub

Sub Parent_Fill()
If isFlex = True Then
    UpdateBookmark "Parent1", ParentBox.Text
    UpdateBookmark "Parent2", ParentBox.Text
    UpdateBookmark "Parent3", ParentBox.Text
    UpdateBookmark "Parent4", ParentBox.Text
    UpdateBookmark "Parent5", ParentBox.Text
    UpdateBookmark "Parent6", ParentBox.Text
    UpdateBookmark "Parent7", ParentBox.Text
    UpdateBookmark "Parent8", ParentBox.Text
    UpdateBookmark "Parent9", ParentBox.Text
    UpdateBookmark "Parent10", ParentBox.Text
    UpdateBookmark "Parent11", ParentBox.Text
    UpdateBookmark "Parent12", ParentBox.Text
    UpdateBookmark "Parent13", ParentBox.Text
    UpdateBookmark "Parent14", ParentBox.Text
    UpdateBookmark "Parent15", ParentBox.Text
    UpdateBookmark "Parent16", ParentBox.Text
End If
If isFT = True Then
    UpdateBookmark "Parent17", ParentBox.Text
    UpdateBookmark "Parent18", ParentBox.Text
    UpdateBookmark "Parent19", ParentBox.Text
    UpdateBookmark "Parent20", ParentBox.Text
    UpdateBookmark "Parent21", ParentBox.Text
    UpdateBookmark "Parent22", ParentBox.Text
    UpdateBookmark "Parent23", ParentBox.Text
    UpdateBookmark "Parent24", ParentBox.Text
    UpdateBookmark "Parent25", ParentBox.Text
    UpdateBookmark "Parent26", ParentBox.Text
    UpdateBookmark "Parent27", ParentBox.Text
End If
UpdateBookmark "Parent28", ParentBox.Text
End Sub

Sub Phone_Fill()
If isFlex = True Then
    UpdateBookmark "Phone1", PhoneBox.Text
    UpdateBookmark "Phone2", PhoneBox.Text
    UpdateBookmark "Phone3", PhoneBox.Text
    UpdateBookmark "Phone4", PhoneBox.Text
    UpdateBookmark "Phone5", PhoneBox.Text
    UpdateBookmark "Phone6", PhoneBox.Text
    UpdateBookmark "Phone7", PhoneBox.Text
    UpdateBookmark "Phone8", PhoneBox.Text
    UpdateBookmark "Phone9", PhoneBox.Text
    UpdateBookmark "Phone10", PhoneBox.Text
    UpdateBookmark "Phone11", PhoneBox.Text
    UpdateBookmark "Phone12", PhoneBox.Text
    UpdateBookmark "Phone13", PhoneBox.Text
    UpdateBookmark "Phone14", PhoneBox.Text
    UpdateBookmark "Phone15", PhoneBox.Text
    UpdateBookmark "Phone16", PhoneBox.Text
End If
If isFT = True Then
    UpdateBookmark "Phone17", PhoneBox.Text
    UpdateBookmark "Phone18", PhoneBox.Text
    UpdateBookmark "Phone19", PhoneBox.Text
    UpdateBookmark "Phone20", PhoneBox.Text
    UpdateBookmark "Phone21", PhoneBox.Text
    UpdateBookmark "Phone22", PhoneBox.Text
    UpdateBookmark "Phone23", PhoneBox.Text
    UpdateBookmark "Phone24", PhoneBox.Text
    UpdateBookmark "Phone25", PhoneBox.Text
    UpdateBookmark "Phone26", PhoneBox.Text
    UpdateBookmark "Phone27", PhoneBox.Text
End If
UpdateBookmark "Phone28", PhoneBox.Text
End Sub

Sub Student_Fill()
If isFlex = True Then
    UpdateBookmark "Student1", StudentBox.Text
    UpdateBookmark "Student2", StudentBox.Text
    UpdateBookmark "Student3", StudentBox.Text
    UpdateBookmark "Student4", StudentBox.Text
    UpdateBookmark "Student5", StudentBox.Text
    UpdateBookmark "Student6", StudentBox.Text
    UpdateBookmark "Student7", StudentBox.Text
    UpdateBookmark "Student8", StudentBox.Text
    UpdateBookmark "Student9", StudentBox.Text
    UpdateBookmark "Student10", StudentBox.Text
    UpdateBookmark "Student11", StudentBox.Text
    UpdateBookmark "Student12", StudentBox.Text
    UpdateBookmark "Student13", StudentBox.Text
    UpdateBookmark "Student14", StudentBox.Text
    UpdateBookmark "Student15", StudentBox.Text
    UpdateBookmark "Student16", StudentBox.Text
    UpdateBookmark "Student17", StudentBox.Text
    UpdateBookmark "Student18", StudentBox.Text
    UpdateBookmark "Student19", StudentBox.Text
    UpdateBookmark "Student20", StudentBox.Text
End If
If isFT = True Then
    UpdateBookmark "Student21", StudentBox.Text
    UpdateBookmark "Student22", StudentBox.Text
    UpdateBookmark "Student23", StudentBox.Text
    UpdateBookmark "Student24", StudentBox.Text
    UpdateBookmark "Student25", StudentBox.Text
    UpdateBookmark "Student26", StudentBox.Text
    UpdateBookmark "Student27", StudentBox.Text
    UpdateBookmark "Student28", StudentBox.Text
    UpdateBookmark "Student29", StudentBox.Text
    UpdateBookmark "Student30", StudentBox.Text
    UpdateBookmark "Student31", StudentBox.Text
End If
UpdateBookmark "Student32", StudentBox.Text
UpdateBookmark "Student33", StudentBox.Text
End Sub

Sub Teacher_Fill()
If isFlex = True Then
    UpdateBookmark "Teacher1", TeacherBox.Text
    UpdateBookmark "Teacher2", TeacherBox.Text
End If
'No FT if Statment needed as no FT Template has a teacher field'
UpdateBookmark "Teacher3", TeacherBox.Text
UpdateBookmark "Teacher4", TeacherBox.Text
End Sub

Sub Username_Fill()
If isFlex = True Then
    UpdateBookmark "Username1", UsernameBox.Text
    UpdateBookmark "Username2", UsernameBox.Text
    UpdateBookmark "Username3", UsernameBox.Text
    UpdateBookmark "Username4", UsernameBox.Text
    UpdateBookmark "Username5", UsernameBox.Text
    UpdateBookmark "Username6", UsernameBox.Text
    UpdateBookmark "Username7", UsernameBox.Text
    UpdateBookmark "Username8", UsernameBox.Text
    UpdateBookmark "Username9", UsernameBox.Text
    UpdateBookmark "Username10", UsernameBox.Text
    UpdateBookmark "Username11", UsernameBox.Text
    UpdateBookmark "Username12", UsernameBox.Text
    UpdateBookmark "Username13", UsernameBox.Text
    UpdateBookmark "Username14", UsernameBox.Text
    UpdateBookmark "Username15", UsernameBox.Text
    UpdateBookmark "Username16", UsernameBox.Text
    UpdateBookmark "Username17", UsernameBox.Text
End If
If isFT = True Then
    UpdateBookmark "Username18", UsernameBox.Text
    UpdateBookmark "Username19", UsernameBox.Text
End If
UpdateBookmark "Username20", UsernameBox.Text
UpdateBookmark "Username21", UsernameBox.Text
End Sub

Sub FOCUSID_Clear()
If isFT = True Then
    ClearBookmark "FOCUSID1"
    ClearBookmark "FOCUSID2"
    ClearBookmark "FOCUSID3"
    ClearBookmark "FOCUSID4"
    ClearBookmark "FOCUSID5"
    ClearBookmark "FOCUSID6"
    ClearBookmark "FOCUSID7"
    ClearBookmark "FOCUSID8"
    ClearBookmark "FOCUSID9"
    ClearBookmark "FOCUSID10"
End If
End Sub

Sub Grade_Clear()
If isFlex = True Then
    ClearBookmark "Grade1"
    ClearBookmark "Grade2"
    ClearBookmark "Grade3"
    ClearBookmark "Grade4"
End If
If isFT = True Then
    ClearBookmark "Grade5"
    ClearBookmark "Grade6"
    ClearBookmark "Grade7"
    ClearBookmark "Grade8"
    ClearBookmark "Grade9"
    ClearBookmark "Grade10"
    ClearBookmark "Grade11"
    ClearBookmark "Grade12"
    ClearBookmark "Grade13"
End If
ClearBookmark "Grade14"
End Sub

Sub UpdateBookmark(BookmarkToUpdate As String, TextToUse As String)
    Dim BMRange As Range
    Set BMRange = ActiveDocument.Bookmarks(BookmarkToUpdate).Range
    BMRange.Text = TextToUse
    ActiveDocument.Bookmarks.Add BookmarkToUpdate, BMRange
End Sub







Private Sub Clear_Course_Click()
Course_Clear
End Sub


Private Sub Clear_CourseBox_Click()
CourseBox.Value = vbNullString
End Sub


Private Sub Clear_Details_Click()
Details_Clear
End Sub


Private Sub Clear_DetailsBox_Click()
DetailsBox.Value = vbNullString
End Sub


Private Sub Clear_Email_Click()
Email_Clear
End Sub


Private Sub Clear_EmailBox_Click()
EmailBox.Value = vbNullString
End Sub


Private Sub Clear_Entries_Click()
Course_Clear
Details_Clear
Email_Clear
FOCUSID_Clear
Grade_Clear
Parent_Clear
Phone_Clear
Student_Clear
Teacher_Clear
Username_Clear
End Sub

Private Sub Clear_FOCUSID_Click()
FOCUSID_Clear
End Sub


Private Sub Clear_FOCUSIDBox_Click()
FOCUSIDBox.Value = vbNullString
End Sub


Private Sub Clear_Grade_Click()
Grade_Clear
End Sub


Private Sub Clear_GradeBox_Click()
GradeBox.Value = vbNullString
End Sub


Private Sub Clear_Parent_Click()
Parent_Clear
End Sub


Private Sub Clear_ParentBox_Click()
ParentBox.Value = vbNullString
End Sub



Private Sub Clear_Phone_Click()
Phone_Clear
End Sub


Private Sub Clear_PhoneBox_Click()
PhoneBox.Value = vbNullString
End Sub




Private Sub Clear_Student_Click()
Student_Clear
End Sub


Private Sub Clear_StudentBox_Click()
StudentBox.Value = vbNullString
End Sub


Private Sub Clear_Teacher_Click()
Teacher_Clear
End Sub


Private Sub Clear_TeacherBox_Click()
TeacherBox.Value = vbNullString
End Sub


Private Sub Clear_TxtBoxes_Click()
CourseBox.Value = vbNullString
DetailsBox.Value = vbNullString
EmailBox.Value = vbNullString
FOCUSIDBox.Value = vbNullString
GradeBox.Value = vbNullString
ParentBox.Value = vbNullString
PhoneBox.Value = vbNullString
StudentBox.Value = vbNullString
TeacherBox.Value = vbNullString
UsernameBox.Value = vbNullString
End Sub

Private Sub Clear_Username_Click()
Username_Clear
End Sub

Private Sub Clear_UsernameBox_Click()
UsernameBox.Value = vbNullString
End Sub


Private Sub Course_Click()

End Sub

Private Sub CourseBox_Change()

End Sub




Private Sub Fill_Course_Click()
Course_Fill
End Sub

Private Sub Fill_Details_Click()
Details_Fill
End Sub


Private Sub Fill_Email_Click()
Email_Fill
End Sub

Private Sub Fill_Entries_Click()
Course_Fill
Details_Fill
Email_Fill
FOCUSID_Fill
Grade_Fill
Parent_Fill
Phone_Fill
Student_Fill
Teacher_Fill
Username_Fill
End Sub

Private Sub Fill_FOCUSID_Click()
FOCUSID_Fill
End Sub

Private Sub Fill_Grade_Click()
Grade_Fill
End Sub


Private Sub Fill_Parent_Click()
Parent_Fill
End Sub


Private Sub Fill_Phone_Click()
Phone_Fill
End Sub

Private Sub Fill_Student_Click()
Student_Fill
End Sub


Private Sub Fill_Teacher_Click()
Teacher_Fill
End Sub


Private Sub Fill_Username_Click()
Username_Fill
End Sub



Private Sub FOCUS_ID_Click()

End Sub

Private Sub Phone_Click()

End Sub



Private Sub toggleFlex_Click()
If isFlex = False Then
    isFlex = True
    toggleFlex.Value = True
Else
    isFlex = False
    toggleFlex.Value = False
End If
End Sub

Private Sub toggleFullTime_Click()
If isFT = False Then
    isFT = True
    toggleFullTime.Value = True
Else
    isFT = False
    toggleFullTime.Value = False
End If
End Sub


Private Sub UserForm_Click()

End Sub


Private Sub Username_Click()

End Sub


Private Sub UsernameBox_Change()

End Sub


