// -*- C++ -*- generated by wxGlade 0.3.5.1 on Sat Aug 20 16:34:47 2005

#include "OVPrefDlg.h"

#include "AVEmbeddedLoader.h"

BEGIN_EVENT_TABLE( OVPrefDlg, wxDialog )
	EVT_BUTTON( ID_FONT, OVPrefDlg::OnFont )
	EVT_BUTTON( ID_BGCOLOR, OVPrefDlg::OnBgColor )
	EVT_BUTTON( ID_BGPICTURE, OVPrefDlg::OnBgPicture )
	EVT_BUTTON( ID_SOUNDTEST, OVPrefDlg::OnSoundTest )
	EVT_BUTTON( ID_COMMON_CLEAR, OVPrefDlg::OnCommonClear )
	EVT_BUTTON( ID_MODLIST_CLEAR, OVPrefDlg::OnModListClear )
	EVT_LIST_ITEM_SELECTED(ID_MODLIST, OVPrefDlg::OnModListItemSelected )
	EVT_COMBOBOX( ID_GENERIC_COMBO, OVPrefDlg::OnGenericComboSelChange )
	EVT_COMBOBOX( ID_OTHER_MOD_COMBO, OVPrefDlg::OnOtherModComboSelChange )
	EVT_LIST_ITEM_SELECTED(ID_OTHER_MOD_PROP_LIST, OVPrefDlg::OnOtherModPropListItemSelected )
	EVT_BUTTON( wxID_CANCEL,  OVPrefDlg::OnCancel )
END_EVENT_TABLE()


OVPrefDlg::OVPrefDlg(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxCLIP_CHILDREN)
		, curGenericMod(NULL)
	{
    // begin wxGlade: OVPrefDlg::OVPrefDlg
    notebook = new wxNotebook(this, -1, wxDefaultPosition, wxDefaultSize, 0);
    module_settings_page = new wxPanel(notebook, -1);
    module_list_page = new wxPanel(notebook, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxCLIP_CHILDREN);
    common_page = new wxPanel(notebook, -1);
    sizer_13_staticbox = new wxStaticBox(common_page, -1, _("Sound"));
    sizer_15_staticbox = new wxStaticBox(common_page, -1, _("Other settings"));
    sizer_1_staticbox = new wxStaticBox(module_list_page, -1, _("Available modules:"));
    sizer_7_staticbox = new wxStaticBox(module_list_page, -1, _("Set the shortcut key to:"));
    sizer_22_staticbox = new wxStaticBox(module_settings_page, -1, _("Phonetic, Chewing, POJ, and Tibetan IME"));
    sizer_24_staticbox = new wxStaticBox(module_settings_page, -1, _("Generic (data table-based) input method"));
    sizer_25_staticbox = new wxStaticBox(module_settings_page, -1, _("Other modules"));
    sizer_3_staticbox = new wxStaticBox(common_page, -1, _("Candidate and notification window"));
    fontBtn = new wxButton(common_page, ID_FONT, _("Font"));
    label_1 = new wxStaticText(common_page, -1, _("Font: "));
    bgColorBtn = new wxButton(common_page, ID_BGCOLOR, _("Background Color"));
    imageBtn = new wxButton(common_page, ID_BGPICTURE, _("Image"));
    filePath_copy_copy = new wxStaticText(common_page, -1, _("Image Path: "));
    label_1_copy = new wxStaticText(common_page, -1, _("Opacity"));
    opacitySlider = new wxSlider(common_page, -1, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS);
    label_2 = new wxStaticText(common_page, -1, _("Preview"));
    previewText = new wxTextCtrl(common_page, -1, _("OpenVanilla"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RICH|wxTE_CENTRE);
    label_5 = new wxStaticText(common_page, -1, _("(Opacity not in effect)"));
    label_3 = new wxStaticText(common_page, -1, _("Warning sound: "));
    soundFile = new wxTextCtrl(common_page, -1, wxT(""));
    soundTest = new wxButton(common_page, ID_SOUNDTEST, _("&Test"));
    label_4 = new wxStaticText(common_page, -1, _("IM toggle key: "));
    switchAlt = new wxCheckBox(common_page, -1, _("Alt"));
    switchCtrl = new wxCheckBox(common_page, -1, _("Ctrl"));
    switchShift = new wxCheckBox(common_page, -1, _("Shift"));
    label_15 = new wxStaticText(common_page, -1, _(" + "));
    const wxString switchKey_choices[] = {
        wxT("")
    };
    switchKey = new wxComboBox(common_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, switchKey_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    common_clear = new wxButton(common_page, ID_COMMON_CLEAR, _("Clear"));
    const wxString modList_choices[] = {
        wxT("")
    };
    modList = new wxCheckListBox(module_list_page, ID_MODLIST, wxDefaultPosition, wxDefaultSize, 1, modList_choices, wxLB_SINGLE|wxLB_HSCROLL);
    modlistAlt = new wxCheckBox(module_list_page, -1, _("Alt"));
    modlistShift = new wxCheckBox(module_list_page, -1, _("Shift"));
    modlistCtrl = new wxCheckBox(module_list_page, -1, _("Ctrl"));
    label_8_copy = new wxStaticText(module_list_page, -1, _("+"));
    const wxString modlistKey_choices[] = {
        _("None")
    };
    modlistKey = new wxComboBox(module_list_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, modlistKey_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    modlistClear = new wxButton(module_list_page, ID_MODLIST_CLEAR, _("Clear"));
    label_7 = new wxStaticText(module_list_page, -1, _("The selected module is loaded \nfrom the following library:\n"));
    label_6 = new wxStaticText(module_list_page, -1, _("Remove unused modules \ncan speed up loading.\nYou have to exit and restart \nexisting applications using \nOpenVanilla or this won't \ntake effect."));
    label_9 = new wxStaticText(module_settings_page, -1, _("Keyboard layout for Phonetics: "));
    const wxString phoneticKeyboardLayout_choices[] = {
        _("Standard Layout")
    };
    phoneticKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, phoneticKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_9_copy = new wxStaticText(module_settings_page, -1, _("Keyboard layout of Chewing: "));
    const wxString chewingKeyboardLayout_choices[] = {
        _("Standard Layout")
    };
    chewingKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, chewingKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_10 = new wxStaticText(module_settings_page, -1, _("Keyboard layout for POJ-Holo: "));
    const wxString pojKeyboardLayout_choices[] = {
        _("Use tone numbers (2, 3, 5, 7, 8) only")
    };
    pojKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, pojKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    pojNoUnicode = new wxCheckBox(module_settings_page, -1, _("Do not output unicode characters but pure ASCII instead"));
    pojNoHanChars = new wxCheckBox(module_settings_page, -1, _("Do not show Han character candidates. (POJ-only output)"));
    label_11 = new wxStaticText(module_settings_page, -1, _("Keyboard layout for Tibetan: "));
    const wxString tibetanKeyboardLayout_choices[] = {
        _("Sambhota Keymap One")
    };
    tibetanKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, tibetanKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_12 = new wxStaticText(module_settings_page, -1, _("Module: "));
    const wxString genericCombo_choices[] = {
        _("None")
    };
    genericCombo = new wxComboBox(module_settings_page, ID_GENERIC_COMBO, wxT(""), wxDefaultPosition, wxDefaultSize, 1, genericCombo_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_13 = new wxStaticText(module_settings_page, -1, _("Maximal radical length: "));
    const wxString genericMaxRadLength_choices[] = {
        _("5")
    };
    genericMaxRadLength = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, genericMaxRadLength_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    shiftSelectionKey = new wxCheckBox(module_settings_page, ID_SHIFT_SELECTION_KEY, _("Space key choose the 1st candidate"));
    autoCompose = new wxCheckBox(module_settings_page, ID_AUTOCOMPOSE, _("Show candidates as you type"));
    hitMaxAndCompose = new wxCheckBox(module_settings_page, ID_HIT_MAX_AND_COMPOSE, _("Commit at maximal radical length"));
    warningBeep = new wxCheckBox(module_settings_page, ID_WARNING_BEEP, _("Warning beep"));
    label_14 = new wxStaticText(module_settings_page, -1, _("Module: "));
    const wxString otherModCombo_choices[] = {
        _("None")
    };
    otherModCombo = new wxComboBox(module_settings_page, ID_OTHER_MOD_COMBO, wxT(""), wxDefaultPosition, wxDefaultSize, 1, otherModCombo_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    otherModPropList = new wxListCtrl(module_settings_page, ID_OTHER_MOD_PROP_LIST, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxSUNKEN_BORDER);
    label_8 = new wxStaticText(module_settings_page, -1, _("Value"));
    modPropEdit = new wxTextCtrl(module_settings_page, -1, wxT(""));
    setBtn = new wxButton(module_settings_page, ID_SET_MOD_PROP_VALUE, _("&Set"));
    output_filter_page = new wxPanel(notebook, -1);
    label_18 = new wxStaticText(this, -1, _("Changes are saved when you close OpenVanilla Preferences"));
    exitBtn = new wxButton(this, wxID_CANCEL, _("E&xit"));

    set_properties();
    do_layout();
    // end wxGlade
	Center();

	InitModuleList();
	InitPOJ();
	InitGenericModules();
	InitOtherModPropList();

}

#if !defined(__WXMSW__)
	#include "ovpref.xpm"
#include ".\ovprefdlg.h"
#endif

void OVPrefDlg::set_properties()
{
    // begin wxGlade: OVPrefDlg::set_properties
    SetTitle(_("Open Vanilla Preferences"));
    opacitySlider->SetSize(wxSize(176, 20));
    switchKey->SetSelection(-1);
    modList->SetSelection(0);
    modlistKey->SetSelection(-1);
    phoneticKeyboardLayout->SetSelection(0);
    chewingKeyboardLayout->SetSelection(0);
    pojKeyboardLayout->SetSelection(0);
    tibetanKeyboardLayout->SetSelection(0);
    genericCombo->SetSelection(-1);
    genericMaxRadLength->SetSelection(-1);
    otherModCombo->SetSelection(-1);
    otherModPropList->SetSize(wxSize(220,100));
    // end wxGlade
	SetIcon(wxICON(ovpref_icon));
}


void OVPrefDlg::do_layout()
{
    // begin wxGlade: OVPrefDlg::do_layout
    wxBoxSizer* top_sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_11 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* module_settings_sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_23 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_25 = new wxStaticBoxSizer(sizer_25_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_5 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_33 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_24 = new wxStaticBoxSizer(sizer_24_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_32 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_31 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_22 = new wxStaticBoxSizer(sizer_22_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_30 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_29 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_28 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_27 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_26_copy = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_26 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_16 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_17 = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_7 = new wxStaticBoxSizer(sizer_7_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_20_copy = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_1 = new wxStaticBoxSizer(sizer_1_staticbox, wxVERTICAL);
    wxBoxSizer* common_page_sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_15 = new wxStaticBoxSizer(sizer_15_staticbox, wxHORIZONTAL);
    wxStaticBoxSizer* sizer_13 = new wxStaticBoxSizer(sizer_13_staticbox, wxHORIZONTAL);
    wxStaticBoxSizer* sizer_3 = new wxStaticBoxSizer(sizer_3_staticbox, wxHORIZONTAL);
    wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* candidate_window_sizer_copy = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_12_copy = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_11_copy = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    sizer_2->Add(fontBtn, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_2->Add(label_1, 0, wxALL|wxFIXED_MINSIZE, 2);
    candidate_window_sizer_copy->Add(sizer_2, 1, wxALL|wxEXPAND, 2);
    sizer_11_copy->Add(bgColorBtn, 0, wxLEFT|wxRIGHT|wxFIXED_MINSIZE, 2);
    sizer_11_copy->Add(imageBtn, 0, wxLEFT|wxRIGHT|wxFIXED_MINSIZE, 2);
    candidate_window_sizer_copy->Add(sizer_11_copy, 0, wxALL|wxEXPAND, 2);
    candidate_window_sizer_copy->Add(filePath_copy_copy, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_12_copy->Add(label_1_copy, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_12_copy->Add(opacitySlider, 1, wxALL, 2);
    candidate_window_sizer_copy->Add(sizer_12_copy, 0, wxALL|wxEXPAND, 2);
    sizer_3->Add(candidate_window_sizer_copy, 0, wxALL|wxEXPAND, 2);
    sizer_4->Add(label_2, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_4->Add(previewText, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 2);
    sizer_4->Add(label_5, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_3->Add(sizer_4, 1, wxALL|wxEXPAND, 2);
    common_page_sizer->Add(sizer_3, 0, wxEXPAND, 0);
    sizer_13->Add(label_3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_13->Add(soundFile, 2, wxALL|wxFIXED_MINSIZE, 2);
    sizer_13->Add(soundTest, 0, wxALL|wxFIXED_MINSIZE, 2);
    common_page_sizer->Add(sizer_13, 0, wxALL|wxEXPAND, 2);
    sizer_15->Add(label_4, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchAlt, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchCtrl, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchShift, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(label_15, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchKey, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(common_clear, 0, wxALL|wxFIXED_MINSIZE, 2);
    common_page_sizer->Add(sizer_15, 0, wxALL|wxEXPAND, 2);
    common_page->SetAutoLayout(true);
    common_page->SetSizer(common_page_sizer);
    common_page_sizer->Fit(common_page);
    common_page_sizer->SetSizeHints(common_page);
    sizer_1->Add(modList, 1, wxALL|wxEXPAND, 1);
    sizer_16->Add(sizer_1, 1, wxALL|wxEXPAND, 2);
    sizer_20_copy->Add(modlistAlt, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_20_copy->Add(modlistShift, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_20_copy->Add(modlistCtrl, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_8->Add(sizer_20_copy, 0, wxALL|wxEXPAND, 2);
    sizer_8->Add(label_8_copy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    sizer_8->Add(modlistKey, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_7->Add(sizer_8, 1, wxEXPAND, 0);
    sizer_7->Add(modlistClear, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_17->Add(sizer_7, 1, wxALL|wxEXPAND, 2);
    sizer_17->Add(label_7, 1, wxALL|wxEXPAND, 4);
    sizer_17->Add(label_6, 0, wxALL|wxEXPAND, 4);
    sizer_16->Add(sizer_17, 0, wxALL, 2);
    module_list_page->SetAutoLayout(true);
    module_list_page->SetSizer(sizer_16);
    sizer_16->Fit(module_list_page);
    sizer_16->SetSizeHints(module_list_page);
    sizer_26->Add(label_9, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_26->Add(phoneticKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_26, 1, wxEXPAND, 0);
    sizer_26_copy->Add(label_9_copy, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_26_copy->Add(chewingKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_26_copy, 1, wxEXPAND, 0);
    sizer_27->Add(label_10, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_27->Add(pojKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_27, 1, wxEXPAND, 0);
    sizer_28->Add(20, 0, 0, wxFIXED_MINSIZE, 0);
    sizer_28->Add(pojNoUnicode, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_28, 1, wxEXPAND, 0);
    sizer_29->Add(20, 0, 0, wxFIXED_MINSIZE, 0);
    sizer_29->Add(pojNoHanChars, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_29, 1, wxEXPAND, 0);
    sizer_30->Add(label_11, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_30->Add(tibetanKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_30, 1, wxEXPAND, 0);
    module_settings_sizer->Add(sizer_22, 1, wxALL|wxEXPAND, 2);
    sizer_31->Add(label_12, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_31->Add(genericCombo, 1, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(sizer_31, 0, wxEXPAND, 0);
    sizer_32->Add(label_13, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_32->Add(genericMaxRadLength, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(sizer_32, 0, wxEXPAND, 0);
    sizer_24->Add(shiftSelectionKey, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(autoCompose, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(hitMaxAndCompose, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(warningBeep, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_23->Add(sizer_24, 1, wxALL|wxEXPAND, 2);
    sizer_33->Add(label_14, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_33->Add(otherModCombo, 1, wxALL|wxFIXED_MINSIZE, 2);
    sizer_25->Add(sizer_33, 0, wxEXPAND, 0);
    sizer_25->Add(otherModPropList, 1, wxALL|wxEXPAND, 2);
    sizer_5->Add(label_8, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_5->Add(modPropEdit, 1, wxFIXED_MINSIZE, 0);
    sizer_5->Add(setBtn, 0, wxLEFT|wxFIXED_MINSIZE, 2);
    sizer_25->Add(sizer_5, 0, wxEXPAND, 0);
    sizer_23->Add(sizer_25, 1, wxALL|wxEXPAND, 2);
    module_settings_sizer->Add(sizer_23, 1, wxEXPAND, 0);
    module_settings_page->SetAutoLayout(true);
    module_settings_page->SetSizer(module_settings_sizer);
    module_settings_sizer->Fit(module_settings_page);
    module_settings_sizer->SetSizeHints(module_settings_page);
    notebook->AddPage(common_page, _("Common"));
    notebook->AddPage(module_list_page, _("Modules List && Hotkeys"));
    notebook->AddPage(module_settings_page, _("Module Settings"));
    notebook->AddPage(output_filter_page, _("Output Filters"));
    top_sizer->Add(new wxNotebookSizer(notebook), 1, wxALL|wxEXPAND, 4);
    sizer_11->Add(label_18, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_11->Add(exitBtn, 0, wxALL|wxFIXED_MINSIZE, 2);
    top_sizer->Add(sizer_11, 0, wxALIGN_RIGHT, 0);
    SetAutoLayout(true);
    SetSizer(top_sizer);
    top_sizer->Fit(this);
    top_sizer->SetSizeHints(this);
    Layout();
    // end wxGlade
}


void OVPrefDlg::OnFont(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnBgColor(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnBgPicture(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnSoundTest(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnCommonClear(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnModListClear(wxCommandEvent& evt)
{
	
}


void OVPrefDlg::OnModListItemSelected(wxListEvent& evt)
{
}


void OVPrefDlg::InitModuleList(void)
{
	int n = loader.modlist().size();
	int i;
	modList->Clear();
	for( i = 0; i < n; ++i )
	{
		OVModule* mod = loader.modlist()[i];
		const char* utf8name = mod->localizedName("zh_TW");
		wxWCharBuffer uname = wxConvUTF8.cMB2WC( utf8name );
#ifdef	UNICODE
		wxString name(uname);
#else
		wxCharBuffer name = wxConvLocal.cWC2MB(uname);
#endif
		modList->Append( name );

		if( 0 == strncmp( mod->identifier(), "OVIMGeneric", 11 ) )
			genericMods.push_back( mod );
		else
		{
			if( strcmp( mod->identifier(), "OVIMPhonetic" ) 
				&& strcmp( mod->identifier(), "OVIMChewing" ) 
				&& strcmp( mod->identifier(), "OVIMPOJ-Holo" ) 
				&& strcmp( mod->identifier(), "OVIMTibetan" ) 
				)
				otherMods.push_back( mod );
		}
	}

	for( i = 0; i < n; ++i )
	{
		OVModule* mod = loader.modlist()[i];
		AVDictionary* dict = loader.dict( mod->identifier() );
		if( dict->getInteger("enable") )
			modList->Check(i, true);
	}
}

void OVPrefDlg::InitGenericModules(void)
{
	int n = genericMods.size();
	int i;
	genericCombo->Clear();
	for( i = 0; i < n; ++i )
	{
		OVModule* mod = genericMods[i];

		const char* utf8name = mod->localizedName("zh_TW");
		wxWCharBuffer uname = wxConvUTF8.cMB2WC( utf8name );
#ifdef	UNICODE
		wxString name(uname);
#else
		wxCharBuffer name = wxConvLocal.cWC2MB(uname);
#endif
		genericCombo->Append( name );
	}

	genericMaxRadLength->Clear();
	for( i = 1; i <= 5; ++i )
		genericMaxRadLength->Append( wxString::Format( wxT("%d"), i) );

	if( !genericMods.empty() )
	{
		genericCombo->SetSelection(0);
		GenericComboSelChange(0);
	}

}

void OVPrefDlg::OnGenericComboSelChange(wxCommandEvent& evt)
{
	SaveGenericConfig();
	GenericComboSelChange(evt.GetSelection());
}

void OVPrefDlg::GenericComboSelChange(int idx)
{
	curGenericMod = genericMods[idx];
	AVDictionary* dict = loader.dict( curGenericMod->identifier() );
	shiftSelectionKey->SetValue( !!dict->getInteger("shiftSelectionKey") );
	autoCompose->SetValue( !!dict->getInteger("autoCompose") );
	hitMaxAndCompose->SetValue( !!dict->getInteger("hitMaxAndCompose") );
	warningBeep->SetValue( !!dict->getInteger("warningBeep") );

	int maxKeySequenceLength = dict->getIntegerWithDefault("maxKeySequenceLength", 5);
	genericMaxRadLength->SetSelection( maxKeySequenceLength - 1 );
}

void OVPrefDlg::InitOtherModPropList(void)
{
	otherModCombo->Clear();
	int n = otherMods.size();
	for( int i = 0; i < n; ++i )
	{
		const char* utf8name = otherMods[i]->localizedName("zh_TW");
		wxWCharBuffer uname = wxConvUTF8.cMB2WC( utf8name );
#ifdef	UNICODE
		wxString name(uname);
#else
		wxCharBuffer name = wxConvLocal.cWC2MB(uname);
#endif
		otherModCombo->Append( name );		
	}

	otherModPropList->InsertColumn( 0, _("Property key") );
	otherModPropList->InsertColumn( 1, _("Value") );

	otherModCombo->SetSelection(0);
	OtherModComboSelChange(0);
}

void OVPrefDlg::OnOtherModComboSelChange(wxCommandEvent& evt)
{
	OtherModComboSelChange(evt.GetSelection());
}

void OVPrefDlg::OnOtherModPropListItemSelected(wxListEvent& evt)
{
	wxListItem item;
	item.m_mask = wxLIST_MASK_TEXT;
	item.m_col = 1;
	item.m_itemId = evt.GetIndex();
	otherModPropList->GetItem(item);
/*	wxRect brc, lrc;
	otherModPropList->GetItemRect(evt.GetIndex(), brc, wxLIST_RECT_BOUNDS);
	otherModPropList->GetItemRect(evt.GetIndex(), lrc, wxLIST_RECT_LABEL);
	brc.SetLeft( lrc.GetRight() );
	static wxTextCtrl* value = new wxTextCtrl(otherModPropList, -1, item.m_text);
	value->Move(brc.GetLeft(), brc.GetTop() );
	value->SetSize(brc.GetWidth(), brc.GetHeight());
	value->SetFocus();
*/
	modPropEdit->SetValue(item.m_text);
}

void OVPrefDlg::OtherModComboSelChange(int idx)
{
	otherModPropList->DeleteAllItems();
	AVDictionary* dict = loader.dict( otherMods[idx]->identifier() );
	for(AVDictIter *it = dict->firstIter(); it; it = dict->nextIter(it) )
	{
//		if( strcmp( "enable", it->getName() ) )
		{
		#ifdef UNICODE
			wxString name = wxConvUTF8.cMB2WC( it->getName() );
			wxString value = wxConvUTF8.cMB2WC( it->getValue() );
		#else
			wxString name = it->getName();
			wxString value = it->getValue();
		#endif
			long i = otherModPropList->InsertItem( otherModPropList->GetItemCount(), name );
			otherModPropList->SetItem( i, 1, value );
		}
	}
	otherModPropList->SetColumnWidth(0, wxLIST_AUTOSIZE );
	otherModPropList->SetColumnWidth(1, wxLIST_AUTOSIZE );
	int w, h;
	otherModPropList->GetClientSize(&w, &h);
	w -= otherModPropList->GetColumnWidth(0);
	if( otherModPropList->GetColumnWidth(1) < w )
		otherModPropList->SetColumnWidth(1, w);
}


void OVPrefDlg::OnCancel(wxCommandEvent& evt)
{
	// Save config
	int i, n = loader.modlist().size();
	for( i = 0; i < n; ++i )
	{
		OVModule* mod = loader.modlist()[i];
		AVDictionary* dict = loader.dict( mod->identifier() );
		dict->setString( "enable", modList->IsChecked(i) ? "1" : "0" );
	}

	// POJ
	AVDictionary* dict = loader.dict("OVIMPOJ-Holo");
	dict->setInteger( "ASCIIOutput", pojNoUnicode->GetValue() );
	dict->setInteger( "fullPOJOutput", pojNoHanChars->GetValue() );

	// Generic
	SaveGenericConfig();

	wxDialog::OnCancel(evt);
}

void OVPrefDlg::SaveGenericConfig(void)
{
	AVDictionary* dict = loader.dict( curGenericMod->identifier() );
	dict->setInteger("shiftSelectionKey", shiftSelectionKey->GetValue());
	dict->setInteger("autoCompose", autoCompose->GetValue());
	dict->setInteger("hitMaxAndCompose", hitMaxAndCompose->GetValue());
	dict->setInteger("warningBeep", warningBeep->GetValue());

	int maxKeySequenceLength = genericMaxRadLength->GetSelection() + 1;
	dict->setInteger( "maxKeySequenceLength", maxKeySequenceLength );
}


void OVPrefDlg::InitPOJ(void)
{
	AVDictionary* dict = loader.dict("OVIMPOJ-Holo");
	int v = dict->getInteger( "ASCIIOutput");
	pojNoUnicode->SetValue( !!dict->getInteger( "ASCIIOutput") );
	pojNoHanChars->SetValue( !!dict->getInteger( "fullPOJOutput") );
}
