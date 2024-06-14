using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnManager : MonoBehaviour
{
    //�X�|�[���|�C���g�I�u�W�F�N�g�i�[�z��
    public Transform[] spawnPositons;


    private void Start()
    {
        //�X�|�[���|�C���g�I�u�W�F�N�g�����ׂĔ�\��
        foreach (var pos in spawnPositons)
        {
            pos.gameObject.SetActive(false);
        }
    }

    /// <summary>
    /// ���X�|�[���n�_�������_���擾����֐�
    /// </summary>
    public Transform GetSpawnPoint()
    {
        //�����_���ŃX�|�[���|�C���g�P�I��ňʒu����Ԃ�
        return spawnPositons[Random.Range(0, spawnPositons.Length)];
    }
}