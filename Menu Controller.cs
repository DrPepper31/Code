using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MenuController : MonoBehaviour
{
   public void Start()
   {
      if (GameStateManager.Instance.GameInProgress)
      {
         Button resumeButton = GameObject.Find("ResumeGameButton").GetComponent<Button>();
         resumeButton.interactable = true;
      }
   }

   public void StartNewGame()
   {
      GameStateManager.Instance.GameInProgress = true;
      GameStateManager.Instance.PlayerPosition = new Vector3(0, 0.5f, 0);

      SceneManager.LoadScene("Level01");
   }

   public void ResumeGame()
   {
      SceneManager.LoadScene("Level01");
   }

   public void QuitGame()
   {
      GameStateManager.Instance.SaveGameState();

#if UNITY_EDITOR
      UnityEditor.EditorApplication.isPlaying = false;
#endif
      Application.Quit();
   }
}
