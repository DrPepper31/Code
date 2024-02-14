using System.IO;
using UnityEngine;

public class GameStateManager : MonoBehaviour
{
   public static GameStateManager Instance;

   public bool GameInProgress = false;
   public Vector3 PlayerPosition = Vector3.zero;

   public void Awake()
   {
      if (Instance != null)
      {
         Destroy(gameObject);
         return;
      }

      Instance = this;
      DontDestroyOnLoad(gameObject);

      if (LoadGameState())
      {
         GameInProgress = true;
      }
   }
   [System.Serializable]
   class SaveData
   {
      public Vector3 PlayerPosition;
   }

   public void SaveGameState()
   {
      SaveData data = new SaveData();
      data.PlayerPosition = this.PlayerPosition;
      string json = JsonUtility.ToJson(data);
      File.WriteAllText(Application.persistentDataPath + "/savefile.json", json);
   }

   public bool LoadGameState()
   {
      string path = Application.persistentDataPath + "/savefile.json";
      if (File.Exists(path))
      {
         string json = File.ReadAllText(path);
         SaveData data = JsonUtility.FromJson<SaveData>(json);
         this.PlayerPosition = data.PlayerPosition;

         return true;
      }

      return false;
   }
}
