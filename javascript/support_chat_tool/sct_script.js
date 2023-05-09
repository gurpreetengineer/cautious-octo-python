// Create chat icon
const chatIcon = document.createElement('div');
chatIcon.id = 'chat-icon';
chatIcon.innerHTML = '&#x1F4AC;';
document.body.appendChild(chatIcon);

// Create chat window
const chatWindow = document.createElement('div');
chatWindow.id = 'chat-window';
document.body.appendChild(chatWindow);

// Toggle chat window visibility on click
chatIcon.addEventListener('click', () => {
  chatWindow.style.display = chatWindow.style.display === 'none' ? 'block' : 'none';
});

// Send chat input to server on form submission
const chatForm = document.querySelector('#chat-form');
const chatInput = document.querySelector('#chat-input');
const chatMessages = document.querySelector('#chat-messages');
chatForm.addEventListener('submit', (event) => {
  event.preventDefault();
  const message = chatInput.value.trim();
  if (message) {
    // Send message to server with AJAX
    // Display server response on chat window
    chatMessages.innerHTML += `<p><strong>You:</strong> ${message}</p>`;
    chatInput.value = '';
  }
});
