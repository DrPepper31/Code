using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using TMPro;


public class PlayerController : MonoBehaviour
{
   public float speed = 1.0f;
   public TextMeshProUGUI countText;
   public GameObject winTextObject;

   private Rigidbody rb;
   private float movementX;
   private float movementY;

   private int count;
   private const int totalPickups = 16;

   private InputActions input = null;

   void Awake()
   {
      rb = GetComponent<Rigidbody>();
      count = 0;
      SetCountText();
      winTextObject.SetActive(false);


      input = new InputActions();
      if (GameStateManager.Instance != null)
      {
         transform.position = GameStateManager.Instance.PlayerPosition;
      }
   }

   void FixedUpdate()
   {
      Vector3 movement = new Vector3(movementX, 0.0f, movementY);
      rb.AddForce(movement * speed);
   }

   void OnMove(InputValue movementValue)
   {
      Vector2 movementVector = movementValue.Get<Vector2>();
      movementX = movementVector.x; 
      movementY = movementVector.y;
   }

   private void OnEnable()
   {
      input.Enable();
      input.Player.GameControl.performed += OnGameControlActionPerformed;
   }

   private void OnDisable()
   {
      input.Enable();
      input.Player.GameControl.performed -= OnGameControlActionPerformed;
   }
   private void OnGameControlActionPerformed(InputAction.CallbackContext context)
   {
      var binding = context.action.GetBindingForControl(context.control);
      var bindingPath = binding.Value.effectivePath;
      if (bindingPath == "*/{Back}")
      {
         if (GameStateManager.Instance != null)
         {
            GameStateManager.Instance.PlayerPosition = transform.position;
         }
         SceneManager.LoadScene("MainMenu");
      }
   }

   private void OnTriggerEnter(Collider other)
   {
      if (other.gameObject.CompareTag("Pickup"))
      {
         other.gameObject.SetActive(false);
         count = count + 1;
         SetCountText();

         if (count == totalPickups)
         {
            winTextObject.SetActive(true);
         }
      }
   }
   private void SetCountText()
   {
      countText.text = "Count: " + count.ToString();
   }
}
