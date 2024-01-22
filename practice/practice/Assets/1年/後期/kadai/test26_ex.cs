using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test26_ex : MonoBehaviour
{
    // �ۑ�26ex
    // �v���C���[�A�G�A�{�X�A�N���X���쐬
    // ���ꂼ��U���́A�U�������A�h�䑮���A�������܂��B
    // �����͉��A���A���̑�����
    // �������A�������A�������@�Ƃ����悤�ȑ���������A
    // ��_�������ꍇ�͍U���͂�2�{�A
    // �ϐ������ꍇ�͍U���͂�0.5�{�ɂȂ�܂��B
    // ��j�������ɍU����2�{�A�������ɍU����0.5�{
    public interface Attribute
    {
        public void attribute();
    }
    public interface Attack
    {
        public void attack();
    }
    public interface Defense
    {
        public void defense();
    }
    public class Player : Attribute, Attack, Defense
    {
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public void attribute()
        {
            attribute_attack = "��";
        }
        public void attack()
        {
            attacks = 50;
        }
        public void defense()
        {
            attribute_defense = "��";
        }
        public int Get_attacks()
        {
            return attacks;
        }
        public string Get_attribute_attack()
        {
            return attribute_attack;
        }
        public string Get_attribute_defense()
        {
            return attribute_defense;
        }
    }
    public class Enemy : Attribute, Attack, Defense
    {
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public void attribute()
        {
            attribute_attack = "��";
        }
        public void attack()
        {
            attacks = 10;
        }
        public void defense()
        {
            attribute_defense = "��";
        }
        public int Get_attacks()
        {
            return attacks;
        }
        public string Get_attribute_attack()
        {
            return attribute_attack;
        }
        public string Get_attribute_defense()
        {
            return attribute_defense;
        }
    }
    public class Boss : Attribute, Attack, Defense
    {
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public void attribute()
        {
            attribute_attack = "��";
        }
        public void attack()
        {
            attacks = 100;
        }
        public void defense()
        {
            attribute_defense = "��";
        }
        public int Get_attacks()
        {
            return attacks;
        }
        public string Get_attribute_attack()
        {
            return attribute_attack;
        }
        public string Get_attribute_defense()
        {
            return attribute_defense;
        }
    }

    // �v���C���[�A�G�A�{�X�̍U���́A���������R�ɐݒ�
    //
    // �v���C���[VS�G
    // �v���C���[VS�{�X
    // �GVS�{�X
    // ���ꂼ��̍U���A�h��ł̃_���[�W�v�Z���s���\������
    //
    // �\����
    // PL�̍U���F���A�З�10
    // �G�̑����F��
    // ���ʔ��Q!! 20�_���[�W
    //
    // ����
    // ���ۃN���X�܂��̓C���^�[�t�F�[�X�N���X��p���Ď���
    // Start is called before the first frame update
    void Start()
    {
        Player player = new Player();
        player.attack();
        player.attribute();
        player.defense();
        int pl_attack= player.Get_attacks();
        string pl_attri_attack = player.Get_attribute_attack();
        string pl_attri_defense = player.Get_attribute_defense();
        Enemy enemy = new Enemy();
        enemy.attack();
        enemy.defense();
        enemy.attribute();
        int ene_attack = enemy.Get_attacks();
        string ene_attri_attack = enemy.Get_attribute_attack();
        string ene_attri_defence = enemy.Get_attribute_defense();
        Boss boss = new Boss();
        boss.attribute();
        boss.attack();
        boss.defense();
        int boss_attack = boss.Get_attacks();
        string boss_attri_attack = boss.Get_attribute_attack();
        string boss_attri_defense = boss.Get_attribute_defense();
        //pl vs ene
        Debug.Log("Player VS Enemy");
        Debug.Log($"Player�̍U�������F{pl_attri_attack}�A�З�{pl_attack}");
        Debug.Log($"Enemy�̖h�䑮���F{ene_attri_defence}");
        if (ene_attri_defence == "��")
        {
            float Info = pl_attack * 0.5f;
            Debug.Log($"���܂���ʂ͂Ȃ��悤���c{Info}�_���[�W");
        }
        else if (ene_attri_defence == "��")
        {
            int Info = pl_attack * 2;
            Debug.Log($"���ʔ��Q!!{Info}�_���[�W");
        }
        else
        {
            Debug.Log($"{pl_attack}�_���[�W");
        }
        // pl vs boss
        Debug.Log($"Player VS Boss");
        Debug.Log($"Player�̍U�������F{pl_attri_attack}�A�З�{pl_attack}");
        Debug.Log($"Boss�̖h�䑮���F{boss_attri_defense}");
        if (boss_attri_defense == "��")
        {
            float Info = pl_attack * 0.5f;
            Debug.Log($"���܂���ʂ͂Ȃ��悤���c{Info}�_���[�W");
        }
        else if(ene_attri_defence == "��")
        {
            int Info = pl_attack * 2;
            Debug.Log($"���ʔ��Q!!{Info}�_���[�W");
        }
        else
        {
            Debug.Log($"{pl_attack}");
        }
        // ene vs boss
        Debug.Log($"Enemy VS Boss");
        Debug.Log($"Enemy�̍U�������F{ene_attri_attack}�A�З�{ene_attack}");
        Debug.Log($"Boss�̖h�䑮���F{boss_attri_defense}");
        if (boss_attri_defense == "��")
        {
            float Info = ene_attack * 0.5f;
            Debug.Log($"���܂���ʂ͂Ȃ��悤���c{Info}�_���[�W");
        }
        else if(ene_attri_defence == "��")
        {
            int Info = ene_attack * 2;
            Debug.Log($"���ʔ��Q!!{Info}�_���[�W");
        }
        else
        {
            Debug.Log($"{ene_attack}�_���[�W");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
