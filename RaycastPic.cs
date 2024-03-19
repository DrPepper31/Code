using System;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;


public class RaycastPic : MonoBehaviour
{
    void Start()
    {
        
    }


    void Update()
    {
        //if M1/leftclick is clicked
        if (Input.GetMouseButtonDown(0))
        {
            Camera mainCamera = Camera.main;

            //makes a raycast from the center of the camera
            Ray ray = mainCamera.ScreenPointToRay(new Vector3(Screen.width / 2, Screen.height / 2, 0));

            //create a RaycastHit variable to store information about the hit
            RaycastHit hit;

            if (Physics.Raycast(ray, out hit))
            {
                //accesses the hit object's name
                string hitObjectName = hit.collider.gameObject.name;

                //prints the hit object's name to the console
                Debug.Log("Hit object: " + hitObjectName);

                if (hitObjectName == "cryptid")
                {
                    //takes a screenshot
                    string screenshotFileName = "CryptidScreenshot.png";
                    ScreenCapture.CaptureScreenshot(screenshotFileName);

                    //prints a message to the console
                    Debug.Log("Screenshot captured: " + screenshotFileName);
                }
                else
                {
                    Debug.Log("THATS NOT A CRYPTID!");
                }
            }
        }
    }
}