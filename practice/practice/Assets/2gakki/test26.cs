using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test26 : MonoBehaviour
{
    // �C���^�[�t�F�[�X�N���X
    // �p����O��Ƃ����N���X
    // �i�p�������N���X�͋@�\���������Ȃ���΂Ȃ�Ȃ��j
    // �C���^�[�t�F�[�X�͕����p���ł���
    public interface IDamage
    {
        void DamegeReaction(); // �_���[�W���A�N�V����
    }
    public interface IAttack
    {
        void AttackReaction(); // �U��
    }

    // IDamage���p��(DamageReaction���������Ȃ���΂Ȃ�Ȃ�)
    public class Player : IDamage, IAttack
    {
        public void DamegeReaction()
        {
            Debug.Log("Player�̃_���[�W");
        }
        public void AttackReaction()
        {
            Debug.Log("Player�̍U��");
        }
    }
    public class Enemy : IDamage
    {
        public void DamegeReaction()
        {
            Debug.Log("Enemy�̃_���[�W");
        }
    }
    public class Boss : IDamage
    {
        public void DamegeReaction()
        {
            Debug.Log("Boss�̃_���[�W");
        }
    }

    Player pl = new Player();
    Enemy em = new Enemy();
    Boss bs = new Boss();

    void Update()
    {
        IDamage dmg = null;
        if (Input.GetKeyDown(KeyCode.Z))
        {
            // Z�L�[��Enemy���U��
            pl.AttackReaction();
            // �_���[�W���A�N�V�������s���͓̂G
            dmg = em;
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            // X�L�[��Boss���U��
            pl.AttackReaction();
            // �_���[�W���A�N�V����
            dmg = bs;
        }
        // �_���[�W�Ώۂ�null����Ȃ����
        if (dmg != null)
        {
            // ���ꂼ��̃_���[�W���A�N�V�������s��
            dmg.DamegeReaction();
        }
    }
}
