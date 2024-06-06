document.addEventListener('DOMContentLoaded', function() {
    // Initial part of the navbar
    const navbarHtml = `
        <a class="navbar-brand" href="#">Catalog Școlar</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav"
            aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav ml-auto" id="navbar">
                <!-- Navbar links will be dynamically added here -->
            </ul>
            <button class="btn btn-outline-danger ml-auto" id="logoutButton">Logout</button>
        </div>
    `;

    // Define the navbar items based on the user type
    const navbarItems = {
        'elev': [
            { name: 'Acasă', link: './start.html' },
            { name: 'Elevi', link: './elevi.html' },
            { name: 'Contact', link: './contact.html' }
        ],
        'profesor': [
            { name: 'Acasă', link: './start.html' },
            { name: 'Profesori', link: './profesori.html' },
            { name: 'Contact', link: './contact.html' }
        ],
        'admin': [
            { name: 'Acasă', link: './start.html' },
            { name: 'Admin', link: './admin.html' },
            { name: 'Contact', link: './contact.html' }
        ],
        // Add more user types as needed
    };

    // Function to generate navbar items based on user type
    function generateNavbarItems(userType) {
        const items = navbarItems[userType] || [];
        return items.map(item => {
            return `<li class="nav-item">
                        <a class="nav-link" href="${item.link}">${item.name}</a>
                    </li>`;
        }).join('');
    }

    // Get the user type from session storage
    const userType = sessionStorage.getItem('userType'); // Retrieve the user type

    // Get the navbar element
    const navbarElement = document.querySelector('.navbar');

    // Add the initial part of the navbar
    navbarElement.insertAdjacentHTML('afterbegin', navbarHtml);

    // Generate and add the navbar items based on the user type
    const navbarContainer = document.getElementById('navbar');
    navbarContainer.innerHTML = generateNavbarItems(userType);

    // Add event listener to the logout button
    document.getElementById('logoutButton').addEventListener('click', function() {
        sessionStorage.removeItem('userType');
        window.location.href = 'login.html'; // Redirect to login page or home page after logout
    });
});
