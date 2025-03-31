document.addEventListener('DOMContentLoaded', function() {
    function loadNavbar(userType) {
        fetch(`get_navbar_items.php?user_type=${userType}`)
        .then(response => response.json())
        .then(data => {
            if (data.success) {
                // Build the navbar structure
                const navbarHtml = `
                    <nav class="navbar navbar-expand-md navbar-dark bg-dark fixed-top">
                        <a class="navbar-brand" href="#">Catalog Școlar</a>
                        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav"
                                aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                            <span class="navbar-toggler-icon"></span>
                        </button>
                        <div class="collapse navbar-collapse" id="navbarNav">
                            <ul class="navbar-nav ml-auto" id="navbar">
                                ${data.navbar_items.map(item => `
                                    <li class="nav-item">
                                        <a class="nav-link" href="${item.item_link}">${item.item_name}</a>
                                    </li>
                                `).join('')}
                                <li class="nav-item">
                                    <a class="nav-link" href="#" id="logoutButton" style="border: 2px solid red; color: red;">Logout</a>
                                </li>
                            </ul>
                        </div>
                    </nav>
                `;

                // Insert the navbar into the placeholder
                document.getElementById('navbarPlaceholder').innerHTML = navbarHtml;

                // Add event listener for logout button
                document.getElementById('logoutButton').addEventListener('click', function(event) {
                    event.preventDefault();
                    sessionStorage.removeItem('userType');
                    window.location.href = 'login.html'; // Redirect to login page
                });
            } else {
                console.error('Error loading navbar items:', data.message);
            }
        })
        .catch(error => {
            console.error('Error:', error);
        });
    }

    // Retrieve user type from session storage
    const userType = sessionStorage.getItem('userType');
    if (userType) {
        loadNavbar(userType);
    } else {
        console.error('User type not found in session storage');
    }
});

