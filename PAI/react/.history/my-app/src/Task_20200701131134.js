import React from 'react';

constructor(props){
    super(props);
    this.state = {
        tekst: "Przyklad",
        checked: true
    }
}

function Task() {
    return ( 
        <div>
            <input type = "checkbox" id="ajdi" name="ajdi"/>
            <label for="ajdi"> I have a bike</label>
        </div>
        
    );
}

export default Task