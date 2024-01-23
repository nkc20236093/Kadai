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
        public string attribute();
    }
    public interface Attack
    {
        public int attack();
    }
    public interface Defense
    {
        public string defense();
    }
    public interface Weakness
    {
        public string weakness();
    }

    public interface Name
    {
        public string name();
    }

    public class Player : Attribute, Attack, Defense,Name,Weakness
    {
        string Weak;
        string names;
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public Player(string n, int a, string att_a, string att_d, string weak)
        {
            names = n;
            attacks = a;
            attribute_attack = att_a;
            attribute_defense = att_d;
            Weak = weak;
        }
        public string name()
        {
            return names;
        }
        public string attribute()
        {
            return attribute_attack;
        }
        public int attack()
        {
            return attacks;
        }
        public string defense()
        {
            return attribute_defense;
        }
        public string weakness()
        {
            return Weak;
        }
        /// <summary>
        /// Player��e
        /// </summary>
        /// <param name="name">�U�����Ă��鑊��̖��O</param>
        /// <param name="partner_attribute_a">�U�����Ă��鑊��̍U������</param>
        /// <param name="partner_attribute__d">�U�����Ă��鑊��̖h�䑮��</param>
        /// <param name="a">�U�����Ă��鑊��̍U����
        public void Damage(string name, string partner_attribute_a, string partner_attribute__d, int a)
        {
            // �\����
            // PL�̍U���F���A�З�10
            // �G�̑����F��
            // ���ʔ��Q!! 20�_���[�W
            Debug.Log($"{name} VS {names}");
            Debug.Log($"{name}�̍U������:{partner_attribute_a}�A�З�{a}");
            Debug.Log($"{names}�̖h�䑮��:{attribute_defense}");
            if (partner_attribute_a == attribute_attack)
            {
                Debug.Log($"���ʔ��Q!!{a * 2}�_���[�W");
            }
            else if (partner_attribute_a == Weak)
            {
                Debug.Log($"���܂���ʂ͂Ȃ��悤���c{a * 0.5f}�_���[�W");
            }
            else if (partner_attribute_a == attribute_defense)
            {
                Debug.Log($"{a}�_���[�W");
            }
        }
    }
    public class Enemy : Attribute, Attack, Defense
    {
        string Weak;
        string names;
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public Enemy(string n, int a, string att_a, string att_d, string weak)
        {
            names = n;
            attacks = a;
            attribute_attack = att_a;
            attribute_defense = att_d;
            Weak = weak;
        }
        public string name()
        {
            return names;
        }
        public string attribute()
        {
            return attribute_attack;
        }
        public int attack()
        {
            return attacks;
        }
        public string defense()
        {
            return attribute_defense;
        }
        public string weakness()
        {
            return Weak;
        }
        /// <summary>
        /// Player��e
        /// </summary>
        /// <param name="name">�U�����Ă��鑊��̖��O</param>
        /// <param name="partner_attribute_a">�U�����Ă��鑊��̍U������</param>
        /// <param name="partner_attribute__d">�U�����Ă��鑊��̖h�䑮��</param>
        /// <param name="a">�U�����Ă��鑊��̍U����
        public void Damage(string name, string partner_attribute_a, string partner_attribute__d, int a)
        {
            // �\����
            // PL�̍U���F���A�З�10
            // �G�̑����F��
            // ���ʔ��Q!! 20�_���[�W
            Debug.Log($"{name} VS {names}");
            Debug.Log($"{name}�̍U������:{partner_attribute_a}�A�З�{a}");
            Debug.Log($"{names}�̖h�䑮��:{attribute_defense}");
            if (partner_attribute_a == attribute_attack)
            {
                Debug.Log($"���ʔ��Q!!{a * 2}�_���[�W");
            }
            else if (partner_attribute_a == Weak)
            {
                Debug.Log($"���܂���ʂ͂Ȃ��悤���c{a * 0.5f}�_���[�W");
            }
            else if (partner_attribute_a == attribute_defense)
            {
                Debug.Log($"{a}�_���[�W");
            }
        }
    }
    public class Boss : Attribute, Attack, Defense
    {
        string Weak;
        string names;
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public Boss(string n, int a, string att_a, string att_d, string weak)
        {
            names = n;
            attacks = a;
            attribute_attack = att_a;
            attribute_defense = att_d;
            Weak = weak;
        }
        public string name()
        {
            return names;
        }
        public string attribute()
        {
            return attribute_attack;
        }
        public int attack()
        {
            return attacks;
        }
        public string defense()
        {
            return attribute_defense;
        }
        public string weakness()
        {
            return Weak;
        }
        /// <summary>
        /// Player��e
        /// </summary>
        /// <param name="name">�U�����Ă��鑊��̖��O</param>
        /// <param name="partner_attribute_a">�U�����Ă��鑊��̍U������</param>
        /// <param name="partner_attribute__d">�U�����Ă��鑊��̖h�䑮��</param>
        /// <param name="a">�U�����Ă��鑊��̍U����
        public void Damage(string name, string partner_attribute_a, string partner_attribute__d, int a)
        {
            // �\����
            // PL�̍U���F���A�З�10
            // �G�̑����F��
            // ���ʔ��Q!! 20�_���[�W
            Debug.Log($"{name} VS {names}");
            Debug.Log($"{name}�̍U������:{partner_attribute_a}�A�З�{a}");
            Debug.Log($"{names}�̖h�䑮��:{attribute_defense}");
            if (partner_attribute_a == attribute_attack)
            {
                Debug.Log($"���ʔ��Q!!{a * 2}�_���[�W");
            }
            else if (partner_attribute_a == Weak)
            {
                Debug.Log($"���܂���ʂ͂Ȃ��悤���c{a * 0.5f}�_���[�W");
            }
            else if (partner_attribute_a == attribute_defense)
            {
                Debug.Log($"{a}�_���[�W");
            }
        }
    }
    void Start()
    {
        // �v���C���[�A�G�A�{�X�̍U���́A���������R�ɐݒ�
        //
        // �v���C���[VS�G
        // �v���C���[VS�{�X
        // �GVS�{�X
        // ���ꂼ��̍U���A�h��ł̃_���[�W�v�Z���s���\������
        //
        // ����
        // ���ۃN���X�܂��̓C���^�[�t�F�[�X�N���X��p���Ď���
        // Start is called before the first frame update

        Player player = new Player("Player", 50, "��", "��","��");
        Boss boss = new Boss("Boss", 100, "��", "��", "��");
        Enemy enemy = new Enemy("Enemy", 10, "��", "��", "��");
        // Player VS Enemy
        player.Damage(enemy.name(), enemy.attribute(), enemy.defense(), enemy.attack());
        // Boss VS Player
        boss.Damage(player.name(), player.attribute(), player.defense(), player.attack());
        // Enemy VS Boss
        enemy.Damage(boss.name(), boss.attribute(), boss.defense(), boss.attack());
    }
}
