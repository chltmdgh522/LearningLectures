using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RouletteController : MonoBehaviour
{
    float rotSpeed = 0; //회전속도
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //클릭하면 회전속도를 설정한다.
        if (Input.GetMouseButtonDown(0)) { //마우스를 눌렀을떄 
            this.rotSpeed = 10; //양수면 반시계방향
        }
        //회전속도만큼 룰렛 회전
        transform.Rotate(0, 0, this.rotSpeed);
        this.rotSpeed * 0.96f;
        
    }
}
