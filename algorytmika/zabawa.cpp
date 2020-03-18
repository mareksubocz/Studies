#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;
class ParticleSystem : public Drawable, public Transformable
{
public:

    ParticleSystem(unsigned int count) :
        m_particles(count),
        m_vertices(Points, count),
        m_lifetime(seconds(3)),
        m_emitter(0, 0)
    {
    }

    void setEmitter(Vector2f position)
    {
        m_emitter = position;
    }

    void update(Time elapsed)
    {
        for (size_t i = 0; i < m_particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= Time::Zero)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<Uint8>(ratio * 255);
        }
    }

private:

    virtual void draw(RenderTarget& target, RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:

    struct Particle
    {
        Vector2f velocity;
        Time lifetime;
    };

    void resetParticle(size_t index)
    {
        // give a random velocity and lifetime to the particle
        float angle = (rand() % 360) * 3.14f / 180.f;
        float speed = (rand() % 50) + 50.f;
        m_particles[index].velocity = Vector2f(cos(angle) * speed, sin(angle) * speed);
        m_particles[index].lifetime = milliseconds((rand() % 2000) + 1000);

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_emitter;
    }

    vector<Particle> m_particles;
    VertexArray m_vertices;
    Time m_lifetime;
    Vector2f m_emitter;
};

int main()
{
    // create the window
    RenderWindow window(VideoMode(512, 256), "Particles");

    // create the particle system
    ParticleSystem particles(1000);

    // create a clock to track the elapsed time
    Clock clock;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // make the particle system emitter follow the mouse
        Vector2i mouse = Mouse::getPosition(window);
        particles.setEmitter(window.mapPixelToCoords(mouse));

        // update it
        Time elapsed = clock.restart();
        particles.update(elapsed);

        // draw it
        window.clear();
        window.draw(particles);
        window.display();
    }

    return 0;
}