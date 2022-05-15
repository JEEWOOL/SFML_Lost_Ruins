#pragma once
#include <SFML/Graphics.hpp>
#include "../Scene.h"
#include "../../Mgr/TextureHolder.h"
#include "../../Mgr/UIManager.h"
#include "../../Object/Player/Player.h"

using namespace sf;

class Npc;

class TestUi
{
private:
	SceneManager* sceneMgr;
	Player player;
	Vector2i resolution;
	std::map<std::string, Texture> texmap;
	Vector2f healthBarsize; // HP�� ������
	Vector2f mpBarsize;		// MP�� ������

	// �׽�Ʈ ���	
	Texture textureback; //�׽�Ʈ���
	Sprite spriteback; //�׽�Ʈ���

	// UI �ؽ�ó
	Texture textureUI;
	Texture textureIN;
	Texture textureMAP;
	Texture textureSQ;
	Texture Blur1;

	//UI ��ũ�� �̹���
	Texture scrollpng;
	Sprite scr1;
	Sprite scr2;

	//UI ���� �̹��� (�Ѽհ�) (�ܰ�)
	Texture weaponpng;
	Sprite wea; // Z����
	Sprite shi; // X����

	//UI ��� �̹���
	Sprite amr1;
	Sprite amr2;

	// UI �̹��� (ex ü��ĭ, ����ĭ, ����ĭ ���..)
	Sprite Blur;
	Sprite HPbar;
	Sprite HPbarLine;
	Sprite MPbar;
	Sprite MPbarLine;
	Sprite BossHPbar;
	Sprite BossHPbarLine;
	Sprite Inventory;
	Sprite Mapicon;
	Sprite Wear1;
	Sprite Wear2;
	Sprite Weapon;
	Sprite Shield;
	Sprite ScrollA;
	Sprite ScrollS;
	Sprite ButtonTab;
	Sprite ButtonM;
	Sprite ButtonA;
	Sprite ButtonS;
	Sprite ButtonZ;
	Sprite ButtonX;
	Sprite Invenwindow; // �κ��丮 â
	Sprite InventoryMAP;// ��â
	Sprite InvenallCS;	// �κ��丮 �� ī�װ� Ŀ��
	
	////////////////////////////////////////////
	//                                        //
	//  �κ��丮 ����ĭ ��������Ʈ / �ؽ�Ʈ   //
	//                                        //
	////////////////////////////////////////////
	
	// ��� ���� ������
	Sprite InvenLongWeapon;
	Sprite InvenWeaponZblock1; // Z���� ��
	Sprite InvenWeaponXblock2; // X���� ��
	Sprite InvenWeaponblock3;
	Sprite InvenWeaponblock4;
	Sprite InvenWeaponblock5;
	Sprite InvenWeaponZblock6; // Z���� �� ����
	Sprite InvenWeaponXblock7; // X���� �� ����
	
	Text textInvenweapon1;
	Text textInvenweapon2;
	Text textInvenweapon3;
	Text textInvenweapon4;
	Text textInvenweapon5;
	Text textInvenweapon6;
	Text textInvenweapon7;
	Text textInvenweapon8;
	Text textInvenweapon9;

	// �ܰ� ���� ������
	Sprite InvenWeaponZblock21; // Z���� ��
	Sprite InvenWeaponXblock22; // X���� ��
	Sprite InvenWeaponblock23;
	Sprite InvenWeaponblock24;
	Sprite InvenWeaponblock25;
	Sprite InvenWeaponZblock26; // Z����� ����
	Sprite InvenWeaponXblock27; // X ����� ����

	Text textInvenweapon21; 
	Text textInvenweapon22; 
	Text textInvenweapon23;
	Text textInvenweapon24;
	Text textInvenweapon25;
	Text textInvenweapon26;
	Text textInvenweapon27;
	Text textInvenweapon28;
	Text textInvenweapon29;

	////////////////////////////////////////////
	//                                        //
	//  �κ��丮 �ֹ�ĭ ��������Ʈ / �ؽ�Ʈ   //
	//                                        //
	////////////////////////////////////////////

	Sprite InvenOrder; // �ֹ�
	Sprite Orderblankrhombus1; //  1. ������ ��ĭ
	Sprite Orderblankrhombus2; // 2. ������ ��ĭ
	Sprite orderitemphotoframe1; // 1. ���� ������ �׸�ĭ
	Sprite orderitemphotoframe2; // 2. ���� ������ �׸�ĭ
	Sprite OdescriptionImage1; // 1. ���� ������ �̹���
	Sprite OdescriptionImage2; // 2. ���� ������ �̹���
	Sprite Oitembackground1; // 1. ���� ������ �̹��� �޹��
	Sprite Oitembackground2; // 2. ���� ������ �̹��� �޹��
	Sprite Orderfullrhombus1; // 1-1. ä���� ������
	Sprite Orderfullrhombus2; // 1-2. ä���� ������
	Sprite Orderfullrhombus3; // 2-1. ä���� ������
	Sprite Orderfullrhombus4; // 2-2. ä���� ������

	Text Otextscrollname1; // 1. ����Ʈ �� ������ �̸�
	Text Otextscrollname2; // 2. ����Ʈ �� ������ �̸�
	Text OtextItemnamefield1; // 1. ���� ������ �̸�
	Text OtextItemnamefield2; // 2. ���� ������ �̸�
	Text Omagictype1; // 1. ����Ÿ��
	Text Omagictype2; // 2. ����Ÿ��
	Text Oattackspeed1; // 1. ���ݼӵ�
	Text Oattackspeed2; // 2. ���ݼӵ�
	Text ODamage1; // 1. ������
	Text ODamage2; // 2. ������
	Text OItemDescription1; // 1. �����ۼ��� �ؽ�Ʈ
	Text OItemDescription2; // 1. �����ۼ��� �ؽ�Ʈ
	Text OItemDescription3; // 1. �����ۼ��� �ؽ�Ʈ
	Text OItemDescription01; // 2. �����ۼ��� �ؽ�Ʈ
	Text OItemDescription02; // 2. �����ۼ��� �ؽ�Ʈ
	Text OItemDescription03; // 2. �����ۼ��� �ؽ�Ʈ
	Text OItemDescription04; // 2. �����ۼ��� �ؽ�Ʈ

	////////////////////////////////////////////
	//                                        //
	// �κ��丮 �Ҹ�ǰĭ ��������Ʈ / �ؽ�Ʈ  //
	//                                        //
	////////////////////////////////////////////

	Sprite InvenSupplies; // �Ҹ�ǰ
	Sprite Suppliesblankrhombus1; //  1. ������ ��ĭ 
	Sprite Suppliesitemphotoframe1; // 1. ���� ������ �׸�ĭ 
	Sprite SuppliesdescriptionImage1; // 1. ���� ������ �̹��� 
	Sprite Suppliesitembackground1; // 1. ���� ������ �̹��� �޹�� 
	Sprite Suppliesrderfullrhombus1; // 1-1. ä���� ������

	Text Suppliestextscrollname1; // 1. ����Ʈ �� ������ �̸� 
	Text SuppliestextItemnamefield1; // 1. ���� ������ �̸� 
	Text Suppliesmagictype1; // 1. ����Ÿ�� 
	Text Suppliesattackspeed1; // 1. ���ݼӵ� 
	Text SuppliesDamage1; // 1. ������ 
	Text SuppliesItemDescription1; // 1. �����ۼ��� �ؽ�Ʈ 
	Text SuppliesItemDescription2; // 1. �����ۼ��� �ؽ�Ʈ 
	Text SuppliesItemDescription3; // 1. �����ۼ��� �ؽ�Ʈ 

	////////////////////////////////////////////
	//                                        //
	//  �κ��丮 ���ĭ ��������Ʈ / �ؽ�Ʈ   //
	//                                        //
	////////////////////////////////////////////

	Sprite InvenEquipment; // ���

	Sprite Equipblankrhombus1; //  1. ������ ��ĭ
	Sprite Equipblankrhombus2; // 2. ������ ��ĭ
	Sprite Equipitemphotoframe1; // 1. ���� ������ �׸�ĭ
	Sprite Equipitemphotoframe2; // 2. ���� ������ �׸�ĭ
	Sprite EquipdescriptionImage1; // 1. ���� ������ �̹���
	Sprite EquipdescriptionImage2; // 2. ���� ������ �̹���
	Sprite Equipitembackground1; // 1. ���� ������ �̹��� �޹��
	Sprite Equipitembackground2; // 2. ���� ������ �̹��� �޹��
	Sprite Equiprderfullrhombus1; // 1-1. ä���� ������
	Sprite Equiprderfullrhombus2; // 1-2. ä���� ������
	Sprite Equiprderfullrhombus3; // 2-1. ä���� ������
	Sprite Equiprderfullrhombus4; // 2-2. ä���� ������

	Text Equiptextscrollname1; // 1. ����Ʈ �� ������ �̸�
	Text Equiptextscrollname2; // 2. ����Ʈ �� ������ �̸�
	Text EquiptextItemnamefield1; // 1. ���� ������ �̸�
	Text EquiptextItemnamefield2; // 2. ���� ������ �̸�
	Text Equipmagictype1; // 1. ���Ÿ��
	Text Equipmagictype2; // 2. ���Ÿ��
	Text Equipattackspeed1; // 1. ������ ��͵�
	Text Equipattackspeed2; // 2. ������ ��͵�
	Text EquipDamage1; // 1. ȿ��
	Text EquipDamage2; // 2. ȿ��
	Text EquipItemDescription1; // 1. �����ۼ��� �ؽ�Ʈ
	Text EquipItemDescription2; // 1. �����ۼ��� �ؽ�Ʈ
	Text EquipItemDescription3; // 1. �����ۼ��� �ؽ�Ʈ
	Text EquipItemDescription01; // 2. �����ۼ��� �ؽ�Ʈ
	Text EquipItemDescription02; // 2. �����ۼ��� �ؽ�Ʈ
	Text EquipItemDescription03; // 2. �����ۼ��� �ؽ�Ʈ
	Text EquipItemDescription04; // 2. �����ۼ��� �ؽ�Ʈ

	////////////////////////////////////////////
	//                                        //
	//  �κ��丮 ����ĭ ��������Ʈ / �ؽ�Ʈ   //
	//                                        //
	////////////////////////////////////////////

	Sprite InvenRelic; // ����
	Sprite Relicblankrhombus1; //  1. ������ ��ĭ 
	Sprite Relicitemphotoframe1; // 1. ���� ������ �׸�ĭ 
	Sprite RelicdescriptionImage1; // 1. ���� ������ �̹��� 
	Sprite Relicitembackground1; // 1. ���� ������ �̹��� �޹�� 
	Sprite Relicrderfullrhombus1; // 1-1. ä���� ������

	Text Relictextscrollname1; // 1. ����Ʈ �� ������ �̸� 
	Text RelictextItemnamefield1; // 1. ���� ������ �̸� 
	Text Relicmagictype1; // 1. ����Ÿ�� 
	Text Relicattackspeed1; // 1. ���ݼӵ� 
	Text RelicDamage1; // 1. ������ 
	Text RelicItemDescription1; // 1. �����ۼ��� �ؽ�Ʈ 
	Text RelicItemDescription2; // 1. �����ۼ��� �ؽ�Ʈ 
	Text RelicItemDescription3; // 1. �����ۼ��� �ؽ�Ʈ 

	////////////////////////////////////////////
	//                                        //
	//  �κ��丮 ���ĭ ��������Ʈ / �ؽ�Ʈ   //
	//                                        //
	////////////////////////////////////////////

	Sprite InvenRecord; // ���(�ڵ���)
	Sprite InvenRecordblock;

	////////////////////////////////////////////
	//                                        //
	//  �κ��丮 ����ĭ ��������Ʈ / �ؽ�Ʈ   //
	//                                        //
	////////////////////////////////////////////

	Sprite InvenKey; // ����
	Sprite InvenKeyblock;


	// �κ��丮 ��������Ʈ
	Sprite InvenCS;
	Sprite Invenname;
	Sprite InvenMap;
	Sprite InvenBtQ;
	Sprite InvenBtW;


	// UI ��� ��Ʈ / �ؽ�Ʈ

	Font fontLostRuins;	
	Text textHPbar;
	Text textMPbar;
	Text textButtonTab; // TAB
	Text textButtonM; // M
	Text textInvenBtQ;
	Text textInvenBtW;
	Text textInven;
	Text textMap;
	Text textButtonX;
	Text textButtonZ;
	Text textButtonS;
	Text textButtonA;


	//Esc �ؽ�Ʈ / ��� / ��������Ʈ
	Texture Escback1;
	Sprite Escback;
	Sprite EscCS;
	Text Continue;
	Text Setting;
	Text End;

	// ESC -> Setting
	Font settingLan;

	Texture texturesetting;
	Texture setBlur1;

	Sprite spriteset1;
	Sprite spriteset2;
	Sprite SettingBtQ;
	Sprite SettingBtW;
	Sprite SettingSet;
	Sprite SettingKey;
	Sprite SettingLeft;
	Sprite SettingRight;
	Sprite SettingESC;
	Sprite setBlur;
	Sprite LanCSL;
	Sprite LanCSR;
	Sprite ResCSL;
	Sprite ResCSR;
	Sprite FullCS;
	Sprite FullCS2;
	Sprite VsyCS;
	Sprite VsyCS2;
	Sprite RenCSL;
	Sprite RenCSR;
	Sprite BattleCS;
	Sprite BattleCS2;
	Sprite MasterBar;
	Sprite MasterCS;
	Sprite UIBar;
	Sprite UICS;
	Sprite SFXBar;
	Sprite SFXCS;
	Sprite MusicBar;
	Sprite MusicCS;
	Sprite ToggleLeft;
	Sprite ToggleRight;
	Sprite ESCBack;
	Sprite settingCS;

	Text SetBack;
	Text SetESC;
	Text Setname;
	Text Keyname;
	Text English;
	Text screensize;
	Text ModeFull;
	Text Back;
	Text Toggle;
	Text TogLeft;
	Text TogRight;
	Text textLanguage;
	Text textResolution;
	Text textFullScreen;
	Text textVsync;
	Text textRenderMode;
	Text textBattleLog;
	Text textMasterVolume;
	Text textUIVolume;
	Text textSFXVolume;
	Text textMusicVolume;
	Text SetBtQ;
	Text SetBtW;


	// ESC -> Keyboard
	Text KeyboardLeft;
	Sprite KeyboardLeftBox;
	Text KeyboardLeftDire;

	Text KeyboardRight;
	Sprite KeyboardRightBox;
	Text KeyboardRightDire;

	Text KeyboardUP;
	Sprite KeyboardUPBox;
	Text KeyboardUPDire;

	Text KeyboardDown;
	Sprite KeyboardDownBox;
	Text KeyboardDownDire;

	Text KeyboardSpace;
	Sprite KeyboardSpaceBox;
	Text KeyboardSpaceDire;

	Text KeyboardC;
	Sprite KeyboardCBox;
	Text KeyboardCDire;

	Text KeyboardZ;
	Sprite KeyboardZBox;
	Text KeyboardZDire;

	Text KeyboardX;
	Sprite KeyboardXBox;
	Text KeyboardXDire;

	Text KeyboardA;
	Sprite KeyboardABox;
	Text KeyboardADire;

	Text KeyboardS;
	Sprite KeyboardSBox;
	Text KeyboardSDire;

	Text KeyboardTab;
	Sprite KeyboardTabBox;
	Text KeyboardTabDire;

	Text KeyboardM;
	Sprite KeyboardMBox;
	Text KeyboardMDire;

	Text KeyboardV;
	Sprite KeyboardVBox;
	Text KeyboardVDire;

	Text KeyboardF;
	Sprite KeyboardFBox;
	Text KeyboardFDire;

	Text KeyboardQ;
	Sprite KeyboardQBox;
	Text KeyboardQDire;

	Text KeyboardW;
	Sprite KeyboardWBox;
	Text KeyboardWDire;


	int menuNum;
	int escNum;
	int settingNum;
	int masterNum;
	int uiNum;
	int sfxNum;
	int musicNum;
	int weaponNum;
	int orderNum;
	int SuppliesNum;
	int EquipmentNum;
	int relicsNum;

	bool inventory;
	bool MAP;
	bool Escmenu;

	bool Zweapon;
	bool Zweaponview;
	bool Xweapon;
	bool Xweaponview;

	bool Zscroll;
	bool Zscrollview;
	bool Xscroll;
	bool Xscrollview;
	bool Zfood;
	bool Zfoodview;
	bool ZEquip;
	bool ZEquipview;
	bool XEquip;
	bool XEquipview;
	bool Zrelics;
	bool Zrelicsview;

	bool Escset;
	bool FullCSsetview;
	bool VsyCSSetview;
	bool BattleCSSetview;
	bool Esckey;

public:

	virtual void Init(SceneManager* sceneManager);
	virtual void Update(float dt, Time playTime, RenderWindow* window, View* mainView, Player& player);
	virtual void Draw(RenderWindow* window, View* mainView);
	void Initstartimg();
	void SeeInven();
	void SeeMap();
	void Escapemenu();
	void EscSetting();
	void ESCsettag();
	void EscKeyboard();

	///////////////////////////////////////////////

	void weaponlist1();
	void weaponlist2();
	void scrollList1();
	void scrollList2();
	void Supplies();
	void EquipList1();
	void EquipList2();
	void relics();

	bool GetEscMenu();

};